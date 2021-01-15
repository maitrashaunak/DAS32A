#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../HAL_Drivers_Source/LCDlib.c "../HAL_Drivers_Source/hal_ADC_pic32mx360f512l .c" "../HAL_Drivers_Source/hal_INT_pic32mx360f512l .c" ../HAL_Drivers_Source/hal_i2c_pic32mx360f512l.c ../HAL_Drivers_Source/hal_spi_pic32mx360f512l.c ../HAL_Drivers_Source/hal_timer_pic32mx360f512l.c ../Source/ADClib.c ../Source/DAClib.c ../Source/DAS32A.c ../Source/libSEE.c ../Source/mylibrary-12-10-19.c ../Source/serallib.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/29028918/LCDlib.o "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o" "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o" ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o ${OBJECTDIR}/_ext/1728301206/ADClib.o ${OBJECTDIR}/_ext/1728301206/DAClib.o ${OBJECTDIR}/_ext/1728301206/DAS32A.o ${OBJECTDIR}/_ext/1728301206/libSEE.o ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o ${OBJECTDIR}/_ext/1728301206/serallib.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/29028918/LCDlib.o.d "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o.d" "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o.d" ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o.d ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o.d ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o.d ${OBJECTDIR}/_ext/1728301206/ADClib.o.d ${OBJECTDIR}/_ext/1728301206/DAClib.o.d ${OBJECTDIR}/_ext/1728301206/DAS32A.o.d ${OBJECTDIR}/_ext/1728301206/libSEE.o.d ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o.d ${OBJECTDIR}/_ext/1728301206/serallib.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/29028918/LCDlib.o ${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l\ .o ${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l\ .o ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o ${OBJECTDIR}/_ext/1728301206/ADClib.o ${OBJECTDIR}/_ext/1728301206/DAClib.o ${OBJECTDIR}/_ext/1728301206/DAS32A.o ${OBJECTDIR}/_ext/1728301206/libSEE.o ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o ${OBJECTDIR}/_ext/1728301206/serallib.o

# Source Files
SOURCEFILES=../HAL_Drivers_Source/LCDlib.c ../HAL_Drivers_Source/hal_ADC_pic32mx360f512l .c ../HAL_Drivers_Source/hal_INT_pic32mx360f512l .c ../HAL_Drivers_Source/hal_i2c_pic32mx360f512l.c ../HAL_Drivers_Source/hal_spi_pic32mx360f512l.c ../HAL_Drivers_Source/hal_timer_pic32mx360f512l.c ../Source/ADClib.c ../Source/DAClib.c ../Source/DAS32A.c ../Source/libSEE.c ../Source/mylibrary-12-10-19.c ../Source/serallib.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX360F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/29028918/LCDlib.o: ../HAL_Drivers_Source/LCDlib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/LCDlib.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/LCDlib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/LCDlib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/LCDlib.o.d" -o ${OBJECTDIR}/_ext/29028918/LCDlib.o ../HAL_Drivers_Source/LCDlib.c  
	
${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l\ .o: ../HAL_Drivers_Source/hal_ADC_pic32mx360f512l\ .c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o".d 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o" 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o.d" -o "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o" "../HAL_Drivers_Source/hal_ADC_pic32mx360f512l .c"  
	
${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l\ .o: ../HAL_Drivers_Source/hal_INT_pic32mx360f512l\ .c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o".d 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o" 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o.d" -o "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o" "../HAL_Drivers_Source/hal_INT_pic32mx360f512l .c"  
	
${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o: ../HAL_Drivers_Source/hal_i2c_pic32mx360f512l.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o.d" -o ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o ../HAL_Drivers_Source/hal_i2c_pic32mx360f512l.c  
	
${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o: ../HAL_Drivers_Source/hal_spi_pic32mx360f512l.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o.d" -o ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o ../HAL_Drivers_Source/hal_spi_pic32mx360f512l.c  
	
${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o: ../HAL_Drivers_Source/hal_timer_pic32mx360f512l.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o.d" -o ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o ../HAL_Drivers_Source/hal_timer_pic32mx360f512l.c  
	
${OBJECTDIR}/_ext/1728301206/ADClib.o: ../Source/ADClib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/ADClib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/ADClib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/ADClib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/ADClib.o.d" -o ${OBJECTDIR}/_ext/1728301206/ADClib.o ../Source/ADClib.c  
	
${OBJECTDIR}/_ext/1728301206/DAClib.o: ../Source/DAClib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAClib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAClib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/DAClib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/DAClib.o.d" -o ${OBJECTDIR}/_ext/1728301206/DAClib.o ../Source/DAClib.c  
	
${OBJECTDIR}/_ext/1728301206/DAS32A.o: ../Source/DAS32A.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAS32A.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAS32A.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/DAS32A.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/DAS32A.o.d" -o ${OBJECTDIR}/_ext/1728301206/DAS32A.o ../Source/DAS32A.c  
	
${OBJECTDIR}/_ext/1728301206/libSEE.o: ../Source/libSEE.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/libSEE.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/libSEE.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/libSEE.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/libSEE.o.d" -o ${OBJECTDIR}/_ext/1728301206/libSEE.o ../Source/libSEE.c  
	
${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o: ../Source/mylibrary-12-10-19.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o.d" -o ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o ../Source/mylibrary-12-10-19.c  
	
${OBJECTDIR}/_ext/1728301206/serallib.o: ../Source/serallib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/serallib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/serallib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/serallib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/serallib.o.d" -o ${OBJECTDIR}/_ext/1728301206/serallib.o ../Source/serallib.c  
	
else
${OBJECTDIR}/_ext/29028918/LCDlib.o: ../HAL_Drivers_Source/LCDlib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/LCDlib.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/LCDlib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/LCDlib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/LCDlib.o.d" -o ${OBJECTDIR}/_ext/29028918/LCDlib.o ../HAL_Drivers_Source/LCDlib.c  
	
${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l\ .o: ../HAL_Drivers_Source/hal_ADC_pic32mx360f512l\ .c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o".d 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o" 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o.d" -o "${OBJECTDIR}/_ext/29028918/hal_ADC_pic32mx360f512l .o" "../HAL_Drivers_Source/hal_ADC_pic32mx360f512l .c"  
	
${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l\ .o: ../HAL_Drivers_Source/hal_INT_pic32mx360f512l\ .c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o".d 
	@${RM} "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o" 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o.d" -o "${OBJECTDIR}/_ext/29028918/hal_INT_pic32mx360f512l .o" "../HAL_Drivers_Source/hal_INT_pic32mx360f512l .c"  
	
${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o: ../HAL_Drivers_Source/hal_i2c_pic32mx360f512l.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o.d" -o ${OBJECTDIR}/_ext/29028918/hal_i2c_pic32mx360f512l.o ../HAL_Drivers_Source/hal_i2c_pic32mx360f512l.c  
	
${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o: ../HAL_Drivers_Source/hal_spi_pic32mx360f512l.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o.d" -o ${OBJECTDIR}/_ext/29028918/hal_spi_pic32mx360f512l.o ../HAL_Drivers_Source/hal_spi_pic32mx360f512l.c  
	
${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o: ../HAL_Drivers_Source/hal_timer_pic32mx360f512l.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/29028918" 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o.d 
	@${RM} ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o.d" -o ${OBJECTDIR}/_ext/29028918/hal_timer_pic32mx360f512l.o ../HAL_Drivers_Source/hal_timer_pic32mx360f512l.c  
	
${OBJECTDIR}/_ext/1728301206/ADClib.o: ../Source/ADClib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/ADClib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/ADClib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/ADClib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/ADClib.o.d" -o ${OBJECTDIR}/_ext/1728301206/ADClib.o ../Source/ADClib.c  
	
${OBJECTDIR}/_ext/1728301206/DAClib.o: ../Source/DAClib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAClib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAClib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/DAClib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/DAClib.o.d" -o ${OBJECTDIR}/_ext/1728301206/DAClib.o ../Source/DAClib.c  
	
${OBJECTDIR}/_ext/1728301206/DAS32A.o: ../Source/DAS32A.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAS32A.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/DAS32A.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/DAS32A.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/DAS32A.o.d" -o ${OBJECTDIR}/_ext/1728301206/DAS32A.o ../Source/DAS32A.c  
	
${OBJECTDIR}/_ext/1728301206/libSEE.o: ../Source/libSEE.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/libSEE.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/libSEE.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/libSEE.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/libSEE.o.d" -o ${OBJECTDIR}/_ext/1728301206/libSEE.o ../Source/libSEE.c  
	
${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o: ../Source/mylibrary-12-10-19.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o.d" -o ${OBJECTDIR}/_ext/1728301206/mylibrary-12-10-19.o ../Source/mylibrary-12-10-19.c  
	
${OBJECTDIR}/_ext/1728301206/serallib.o: ../Source/serallib.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/_ext/1728301206" 
	@${RM} ${OBJECTDIR}/_ext/1728301206/serallib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1728301206/serallib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1728301206/serallib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c ${MP_CC} $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../Include" -I"../HAL_Drivers_Header" -MMD -MF "${OBJECTDIR}/_ext/1728301206/serallib.o.d" -o ${OBJECTDIR}/_ext/1728301206/serallib.o ../Source/serallib.c  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)    -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}       -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map" 
else
dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}       -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}/pic32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/DAS32A.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
