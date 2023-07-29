/* 
 * Gmu Music Player
 *
 * Copyright (c) 2006-2011 Johannes Heimansberg (wejp.k.vu)
 *
 * File: hw_unknown.c  Created: 090629
 *
 * Description: Hardware specific header file for unknown devices (such as PCs)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2 of
 * the License. See the file COPYING in the Gmu's main directory
 * for details.
 */
#include <stdio.h>
#ifndef GMU_DISABLE_OSS_MIXER
#include "oss_mixer.h"
#endif
#include "debug.h"
#include "hw_funkey.h"

static int display_on_value = 100, keyboard_on_value = 100;
static int selected_mixer = -1;

void hw_display_off(void)
{
	char  tmp[5];
	FILE *f;

	wdprintf(V_DEBUG, "hw_funkey", "Display off requested.\n");
	
	if ((f = fopen("/sys/class/backlight/backlight/bl_power", "w"))) {
		fprintf(f, "1\n");
		fclose(f);
	}
	
}

void hw_display_on(void)
{
	FILE *f;

	wdprintf(V_DEBUG, "hw_funkey", "Display on requested.\n");
	if ((f = fopen("/sys/class/backlight/backlight/bl_power", "w"))) {
		fprintf(f, "0\n");
		fclose(f);
	}
}

int hw_open_mixer(int mixer_channel)
{
#ifndef GMU_DISABLE_OSS_MIXER
	int res = oss_mixer_open();
	selected_mixer = mixer_channel;
	wdprintf(V_INFO, "hw_unknown", "Selected mixer: %d\n", selected_mixer);
	return res;
#else
	return 0;
#endif
}

void hw_close_mixer(void)
{
#ifndef GMU_DISABLE_OSS_MIXER
	oss_mixer_close();
#endif
}

void hw_set_volume(int volume)
{
#ifndef GMU_DISABLE_OSS_MIXER
	if (selected_mixer >= 0) {
		if (volume >= 0) oss_mixer_set_volume(selected_mixer, volume);
	} else {
		wdprintf(V_INFO, "hw_unknown", "No suitable mixer available.\n");
	}
#endif
}

void hw_detect_device_model(void)
{
}

const char *hw_get_device_model_name(void)
{
	return "Funkey-S";
}
