
void __core_init(void) {

#if CORTEX_MODEL == 7
    SCB_EnableICache();
    SCB_EnableDCache();
#endif

    // Need to add 
#if defined(__IMXRT1062__)
	IOMUXC_GPR_GPR17 = (uint32_t)&_flexram_bank_config;
	IOMUXC_GPR_GPR16 = 0x00200007;
	IOMUXC_GPR_GPR14 = 0x00AA0000;

	__asm__ volatile("dsb":::"memory");
	__asm__ volatile("isb":::"memory");

#elif defined(__IMXRT1021__)
	// IOMUXC_GPR_GPR17 = (uint32_t)&_flexram_bank_config;
	IOMUXC_GPR_GPR17 = 0x000057A5;
	IOMUXC_GPR_GPR16 = 0x00200007;
	IOMUXC_GPR_GPR14 = 0x00AA0000;

	__asm__ volatile("dsb":::"memory");
	__asm__ volatile("isb":::"memory");
#endif

}

void __early_init(void) {}

void __late_init(void) {}


/*
 * Adding bootdata example from pjrc teensy

#include <stdint.h>

extern void ResetHandler(void);
extern unsigned long _estack;
extern unsigned long _flashimagelen;

*/
/*
__attribute__ ((section(".bootdata"), used))
const uint32_t BootData[3] = {
	0x60000000, // Flash base -> boot start location
	(uint32_t)&_flashimagelen, // flash size?
	0 // Plugin flag
};
*/
/*

__attribute__ ((section(".csf"), used))
const uint32_t hab_csf[768];	// placeholder for HAB signature
*/
/*

__attribute__ ((section(".ivt"), used))
const uint32_t ImageVectorTable[8] = {
	0x432000D1,		// header
	(uint32_t)&ResetHandler,// program entry
	0,			// reserved
	0,			// dcd
	(uint32_t)BootData,	// abs address of boot data
	(uint32_t)ImageVectorTable, // self
	(uint32_t)hab_csf,	// command sequence file
	0			// reserved
};

*/
/*

// Since uint32_t is 32bits the 1 value has 4 bytes (as in reference manual)
__attribute__ ((section(".flashconfig"), used))
uint32_t FlexSPI_NOR_Config[128] = {
	// 448 byte common FlexSPI configuration block, 8.6.3.1 page 223 (RT1060 rev 0)
	// 448 byte common FlexSPI configuration block, 9.6.3.1 page 207 (RT1020 rev ?)
	// MCU_Flashloader_Reference_Manual.pdf, 8.2.1, Table 8-2, page 72-75
    // Value,       // Name             (offset)
	0x42464346,		// Tag				0x000
	0x56010000,		// Version          0x004
	0,			    // reserved
	0x00030301,		// columnAdressWidth,dataSetupTime,dataHoldTime,readSampleClkSrc
                    // ->               0x00C (note: data == cs)

	0x00000000,		// waitTimeCfgCommands,-,deviceModeCfgEnable
                    // ->               0x010

	0,			    // deviceModeSeq    0x014
	0, 			    // deviceModeArg    0x018
	0x00000000,		// -,-,-,configCmdEnable
                    // ->               0x01C

	0,			    // configCmdSeqs[3:0]	0x020
	0,			    // configCmdSeqs[7:4]
	0,			    // configCmdSeqs[11:8]
	0,              // reserved

	0,			    // cfgCmdArgs[0:3]		0x030
	0,			    // cfgCmdArgs[7:4]
	0,			    // cfgCmdArgs[11:8]
	0,              // reserved

	0x00000000,		// controllerMiscOption
                    // ->               0x040
	0x00080401,		// lutCustomSeqEnable,serialClkFreq,sflashPadType,deviceType
                    // ->               0x044
	0,			    // reserved
	0,			    // reserved

#if defined(ARDUINO_TEENSY40)
	0x00200000,		// sflashA1Size			0x50
#elif defined(ARDUINO_TEENSY41)
	0x00800000,		// sflashA1Size			0x50
#elif defined(ARDUINO_TEENSY_MICROMOD)
	0x01000000,		// sflashA1Size			0x50
#elif defined(MIMXRT1021EVK_EVAL_BRD)
	0x00100000,		// sflashA1Size			0x50
#else
#error "Unknow flash chip size";
#endif
	0,			    // sflashA2Size     0x054
	0,			    // sflashB1Size     0x058
	0,			    // sflashB2Size     0x05C

	0,			    // csPadSettingOverride		0x060
	0,			    // sclkPadSettingOverride   0x064
	0,			    // dataPadSettingOverride   0x068
	0,			    // dqsPadSettingOverride    0x06C

	0,			    // timeoutInMs	    0x070
	0,			    // commandInterval  0x074
	0,			    // dataValidTime    0x078
	0x00000000,		// busyBitPolarity,busyOffset
                    // ->               0x07C

	0x0A1804EB,		// lookupTable[0]		0x080
	0x26043206,		// lookupTable[1]
	0,			    // lookupTable[2]
	0,			    // lookupTable[3]

	0x24040405,		// lookupTable[4]		0x090
	0,			    // lookupTable[5]
	0,			    // lookupTable[6]
	0,			    // lookupTable[7]

	0,			    // lookupTable[8]		0x0A0
	0,			    // lookupTable[9]
	0,			    // lookupTable[10]
	0,			    // lookupTable[11]

	0x00000406,		// lookupTable[12]		0x0B0
	0,			    // lookupTable[13]
	0,			    // lookupTable[14]
	0,			    // lookupTable[15]

	0,			    // lookupTable[16]		0x0C0
	0,			    // lookupTable[17]
	0,			    // lookupTable[18]
	0,			    // lookupTable[19]

	0x08180420,		// lookupTable[20]		0x0D0
	0,			    // lookupTable[21]
	0,			    // lookupTable[22]
	0,			    // lookupTable[23]

	0,			    // lookupTable[24]		0x0E0
	0,			    // lookupTable[25]
	0,			    // lookupTable[26]
	0,			    // lookupTable[27]

	0,			    // lookupTable[28]		0x0F0
	0,			    // lookupTable[29]
	0,			    // lookupTable[30]
	0,			    // lookupTable[31]

	0x081804D8,		// lookupTable[32]		0x100
	0,			    // lookupTable[33]
	0,			    // lookupTable[34]
	0,			    // lookupTable[35]

	0x08180402,		// lookupTable[36]		0x110
	0x00002004,		// lookupTable[37]
	0,			    // lookupTable[38]
	0,			    // lookupTable[39]

	0,			    // lookupTable[40]		0x120
	0,			    // lookupTable[41]
	0,			    // lookupTable[42]
	0,			    // lookupTable[43]

	0x00000460,		// lookupTable[44]		0x130
	0,			    // lookupTable[45]
	0,			    // lookupTable[46]
	0,			    // lookupTable[47]

	0,			    // lookupTable[48]		0x140
	0,			    // lookupTable[49]
	0,			    // lookupTable[50]
	0,			    // lookupTable[51]

	0,			    // lookupTable[52]		0x150
	0,			    // lookupTable[53]
	0,			    // lookupTable[54]
	0,			    // lookupTable[55]

	0,			    // lookupTable[56]		0x160
	0,			    // lookupTable[57]
	0,			    // lookupTable[58]
	0,			    // lookupTable[59]

	0,			    // lookupTable[60]		0x170
	0,			    // lookupTable[61]
	0,			    // lookupTable[62]
	0,			    // lookupTable[63]

	0,			    // LUT 0: Read			0x180
	0,			    // LUT 1: ReadStatus
	0,			    // LUT 3: WriteEnable
	0,			    // LUT 5: EraseSector

	0,			    // LUT 9: PageProgram		0x190
	0,			    // LUT 11: ChipErase
	0,			    // LUT 15: Dummy
	0,			    // LUT unused?

	0,			    // LUT unused?			0x1A0
	0,			    // LUT unused?
	0,			    // LUT unused?
	0,			    // LUT unused?

	0,			    // reserved			0x1B0
	0,			    // reserved
	0,			    // reserved
	0,			    // reserved

	// 64 byte Serial NOR configuration block, 8.6.3.2, page 346

	256,			// pageSize			0x1C0
	4096,			// sectorSize
	1,			    // ipCmdSerialClkFreq
	0,			    // reserved

	0x00010000,		// block size		0x1D0
	0,			    // reserved
	0,			    // reserved
	0,			    // reserved

	0,			    // reserved			0x1E0
	0,			    // reserved
	0,			    // reserved
	0,			    // reserved

	0,			    // reserved			0x1F0
	0,			    // reserved
	0,			    // reserved
	0			    // reserved
};

*/
