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

# Platform Overrides
PLATFORM = $(shell)

# Architecture Specific Flags
CPU = cortex-m0plus
ARCH = thumb
SPECS = nosys.specs

# Platform Specific Flags
LINKER_FILE = MKL25Z128xxx4_flash.ld 

# Compile Defines
#CC = arm-none-eabi-gcc
ifeq ($(PLATFORM), HOST)
	CC = gcc
else
	CC = arm-none-eabi-gcc
endif
LD = arm-none-eabi-ld
TARGET = demo
ifeq ($(PLATFORM), HOST)
else
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
endif
ifeq ($(PLATFORM), HOST)
	CFLAGS = -Wall -Werror -g -O0 -std=c99
else
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
endif
CPPFLAGS = -E -MD
ASMFLAGS = -S
PREPRO = $(SRCS:.c=.i)
DEPEND = $(SRCS:.c=.d)
ASSEMBLY = $(SRC:.c=.asm)
OBJS = $(SRCS:.c=.o)

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
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(PREPRO) $(DEPEND) *.asm $(OBJS) $(TARGET).out $(TARGET).map

