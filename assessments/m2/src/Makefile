#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the cortex-M0+ build system
#
# Use: make [TARGET] [OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
#
# Overrides:
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#
#------------------------------------------------------------------------------
include sources.mk
PREPRO = $(SOURCES:.c=.i)
DEPEND = $(SOURCES:.c=.d)
ASSEMBLY = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)

# Platform Overrides
PLATFORM = $(shell)

# Architecture Specific Flags
CPU = cortex-m4
ARCH1 = thumb
ARCH2 = armv7e-m
FLOAT = hard
FPU = fpv4-sp-d16
SPECS = nosys.specs

# Platform Specific Flags
LINKER_FILE = ../msp432p401r.lds 

# Compile Defines
GENERAL = -Wall -Werror -g -O0 -std=c99
ifeq ($(PLATFORM), HOST)
	CC = gcc -D$(PLATFORM) -I$(COMMONADD) -I$(MSP432ADD) -I$(CMSISADD)
else
	CC = arm-none-eabi-gcc -D$(PLATFORM) -I$(COMMONADD) -I$(MSP432ADD) -I$(CMSISADD)
endif
LD = arm-none-eabi-ld
TARGET = c1m2
ifeq ($(PLATFORM), HOST)
else
	LDFLAGS = -Wl,-Map=$(TARGET).map -T$(LINKER_FILE)
endif
ifeq ($(PLATFORM), HOST)
	CFLAGS = $(GENERAL) 
else
	CFLAGS = -mcpu=$(CPU) -m$(ARCH1) -march=$(ARCH2) -mfloat-abi=$(FLOAT)\
	         -mfpu=$(FPU) --specs=$(SPECS) $(GENERAL)
endif
CPPFLAGS = -E -MD
ASMFLAGS = -S


%.i: %.c
	$(CC) $(CPPFLAGS) $< -o $@

%.asm: %.c
	$(CC) $(ASMFLAGS) $< -o $@

$(TARGET).asm: $(TARGET).out
	$(CC) $(ASMFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

.PHONY: compile-all
compile-all: $(OBJS)


.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(PREPRO) $(DEPEND) $(ASSEMBLY) $(OBJS) $(TARGET).out $(TARGET).map

