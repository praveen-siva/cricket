######### installed program #############
#VPATH = -I./Source/

OUTPUT = Match

COMPILER =g++

######### installed library(*.a) #############
INST_LIBS = lib

######### installed shared library(*.so) #############
INST_SHLIBS = libDev

LINK_SHLIB_CXX=

######### install headers(*.h)  #############
VPATH += -I../Include
INST_HEADERS = .h
INST_HEADERS = .h
INST_HEADERS = .h

######### compiled sources  #############
DEV_SRCS += main.cpp
DEV_SRCS += Score.cpp
DEV_SRCS += Innings.cpp

#Enable the below flag when USB device is supported
#1 to ENABLE, 0 to Disable

IS_USB_SUPPORTED = 0
ifeq (${IS_USB_SUPPORTED}, 1)
CPPFLAGS += -DUSB_ENABLED
libDEV_SRCS += Dev_USB.cpp
endif

######### add library path #############
#LDFLAGS += -L
#LDFLAGS += -g -Wl,--gc-sections
#LDFLAGS += -lrt

#BINARY_FILES = Dev_USB.o Dev_I2c.o Dev_SPI.o Dev_Main.o

# compile C source files into object files.
#%$(BINARY_FILE).o: %.cpp
#	$(COMPILER) -c $<


include ../Makefile
