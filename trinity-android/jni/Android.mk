LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := trinity
LOCAL_SRC_FILES := $(wildcard *.c) \
	           $(wildcard children/*.c) \
	           $(wildcard ioctls/*.c) \
	           $(wildcard net/*.c) \
	           $(wildcard syscalls/*.c) \


LOCAL_ARM_MODE := arm
CFLAGS += -Wall -W -g -O2 -Wimplicit -D_FORTIFY_SOURCE=2 -D__linux__ -Wdeclaration-after-statement 
CFLAGS += -Wformat=2 -Winit-self -Wnested-externs -Wpacked -Wshadow -Wswitch-enum -Wundef
CFLAGS += -Wwrite-strings -Wno-format-nonliteral -Wstrict-prototypes -Wmissing-prototypes
CFLAGS += -Iinclude
LDFLAGS += -rdynamic
LOCAL_C_INCLUDES += include
LOCAL_C_INCLUDES += syscalls
include $(BUILD_EXECUTABLE)
