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

# Add your Source files to this variable
SOURCES = main.c\
		  memory.c\
		  interrupts_msp432p401r_gcc.c\
		  startup_msp432p401r_gcc.c\
		  system_msp432p401r.c

# Add your include paths to this variable
COMMONADD = ../include/common/
MSP432ADD = ../include/msp432/
CMSISADD = ../include/CMSIS/
INCLUDES = $(COMMONADD)memory.h\
		   $(COMMONADD)platform.h\
		   $(MSP432ADD)msp432p401r.h\
		   $(MSP432ADD)msp_compatibility.h\
		   $(MSP432ADD)system_msp432p401r.h\
		   $(CMSISADD)cmsis_gcc.h\
		   $(CMSISADD)core_cm4.h\
		   $(CMSISADD)core_cmFunc.h\
		   $(CMSISADD)core_cmInstr.h\
		   $(CMSISADD)core_cmSimd.h


