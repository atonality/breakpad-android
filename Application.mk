APP_ABI := armeabi armeabi-v7a arm64-v8a x86 x86_64
APP_STL := gnustl_shared
APP_CPPFLAGS += -std=gnu++11 -fexceptions

ifeq ($(APP_DEBUG), true)
APP_CFLAGS += -g
endif