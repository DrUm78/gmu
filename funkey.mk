# Generated Gmu config
RELEASE_BUILD=1
CC=/opt/FunKey-sdk/bin/arm-funkey-linux-musleabihf-gcc
SDL_CFLAGS=-I/opt/FunKey-sdk/arm-funkey-linux-musleabihf/sysroot/usr/bin/../../usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -Icross/funkey/include
SDL_LIB=-L/opt/FunKey-sdk/arm-funkey-linux-musleabihf/sysroot/usr/bin/../../usr/lib -lSDL -lpthread
CFLAGS=-D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -Ofast   -I/opt/FunKey-sdk/arm-funkey-linux-musleabihf/sysroot/usr/include  $(SDL_CFLAGS) -fsigned-char -D_REENTRANT -DUSE_MEMORY_H 
LFLAGS=   -Lcross/funkey/lib -Wl,-export-dynamic
LFLAGS_CORE=
LIBS_CORE=
DECODERS_TO_BUILD= decoders/mpg123.so decoders/vorbis.so decoders/flac.so
FRONTENDS_TO_BUILD= frontends/sdl.so frontends/gmuhttp.so frontends/log.so frontends/notify.so
TARGET=funkey
TOOLS_TO_BUILD= gmu

