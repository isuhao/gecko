/*
Copyright 2011 Bastian Loeher, Roland Wirth

This file is part of GECKO.

GECKO is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GECKO is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SIS3302_GAMMA_V1410_H
#define SIS3302_GAMMA_V1410_H


/***************************************************************************/
/*                                                                         */
/*  Filename: SIS3302_gamma_v1410.h                                                    */
/*                                                                         */
/*  Funktion: headerfile for SIS3302 for gamma firmware rev. 1410          */
/*                                                                         */
/*  Autor:                TH                                               */
/*  date:                 10.01.2006                                       */
/*  last modification:    23.09.2011                                       */
/*                                                                         */
/* ----------------------------------------------------------------------- */
/*                                                                         */
/*  SIS  Struck Innovative Systeme GmbH                                    */
/*                                                                         */
/*  Harksheider Str. 102A                                                  */
/*  22399 Hamburg                                                          */
/*                                                                         */
/*  Tel. +49 (0)40 60 87 305 0                                             */
/*  Fax  +49 (0)40 60 87 305 20                                            */
/*                                                                         */
/*  http://www.struck.de                                                   */
/*                                                                         */
/*  � 2006                                                                 */
/*                                                                         */
/***************************************************************************/

#include <inttypes.h>

#define SIS3302_V1410_MAX_NOF_LWORDS          0x1000000 // 64 MB == 16 MWords
#define SIS3302_V1410_MAX_NOF_RAW_SAMPLES     65532
#define SIS3302_V1410_MAX_NOF_ENERGY_SAMPLES  510
#define SIS3302_V1410_MEM_PAGE_LENGTH_SAMPLES 0x0400000
#define SIS3302_V1410_MEM_PAGE_LENGTH_WORDS   0x0200000
#define SIS3302_V1410_MEM_PAGE_LENGTH_BYTES   0x0800000
#define SIS3302_V1410_MSK_PAGE_LENGTH_SAMPLES 0x03ffffc // 8 MB == 2 MWords

#define SIS3302_V1410_CONTROL_STATUS          0x00  /* read/write; D32 */
#define SIS3302_V1410_MODID                   0x04  /* read only; D32 */
#define SIS3302_V1410_IRQ_CONFIG              0x08  /* read/write; D32 */
#define SIS3302_V1410_IRQ_CONTROL             0x0C  /* read/write; D32 */
#define SIS3302_V1410_ACQUISITION_CONTROL     0x10  /* read/write; D32 */

#define SIS3302_V1410_BROADCAST_SETUP 0x0030
#define SIS3302_V1410_ADC_MEMORY_PAGE 0x0034

#define SIS3302_V1410_DAC_CTRL_STATUS 0x0050
#define SIS3302_V1410_DAC_DATA        0x0054

#define SIS3302_V1410_JTAG_TEST       0x0060
#define SIS3302_V1410_JTAG_CTRL       0x0064

#define SIS3302_V1410_MCA_SCAN_NOF_HISTOGRAMS    0x0080
#define SIS3302_V1410_MCA_SCAN_HISTOGRAM_COUNTER 0x0084
#define SIS3302_V1410_MCA_SCAN_LNE_PRESCALER     0x0088
#define SIS3302_V1410_MCA_SCAN_CTRL              0x008C

#define SIS3302_V1410_MCA_MSCAN_NOF_SCANS       0x0090
#define SIS3302_V1410_MCA_MSCAN_COUNTER         0x0094
#define SIS3302_V1410_MCA_MSCAN_LAST_H_COUNT    0x0098

#define SIS3302_V1410_RESET         0x0400
#define SIS3302_V1410_LOGIC_RESET   0x0404

#if defined(SIS3302_V1410_MCA_MODE)
#define SIS3302_V1410_MCA_SCAN_LNE              0x0410
#define SIS3302_V1410_MCA_SCAN_ARM              0x0414
#define SIS3302_V1410_MCA_SCAN_ENABLE           0x0418
#define SIS3302_V1410_MCA_SCAN_DISABLE          0x041C
#define SIS3302_V1410_MCA_MSCAN_START_RESET     0x0420
#define SIS3302_V1410_MCA_MSCAN_ARM_SCAN_ARM    0x0424
#define SIS3302_V1410_MCA_MSCAN_ARM_SCAN_ENABLE 0x0428
#define SIS3302_V1410_MCA_MSCAN_DISABLE         0x042C
#else
#define SIS3302_V1410_SAMPLE_LOGIC_RESET        0x0410
#define SIS3302_V1410_DISARM                    0x0414
#define SIS3302_V1410_TRIGGER                   0x0418
#define SIS3302_V1410_TIMESTAMP_CLEAR           0x041C
#define SIS3302_V1410_DISARM_AND_ARM_BANK1      0x0420
#define SIS3302_V1410_DISARM_AND_ARM_BANK2      0x0424
#define SIS3302_V1410_RESET_DDR2                0x0428
#endif

/* Event information for all ADC groups */

#define SIS3302_V1410_EVENT_CONFIG_ALL          0x01000000
#define SIS3302_V1410_END_ADDRESS_THR_ALL       0x01000004
#define SIS3302_V1410_PRETRIGGER_AND_GATE_ALL   0x01000008
#define SIS3302_V1410_RAW_BUFFER_CONFIG_ALL     0x0100000C

#define SIS3302_V1410_ENERGY_SETUP_GP_ALL       0x01000040
#define SIS3302_V1410_ENERGY_GATE_LEN_ALL       0x01000044
#define SIS3302_V1410_ENERGY_SAMPLE_LEN_ALL     0x01000048
#define SIS3302_V1410_ENERGY_START_IDX1_ALL     0x0100004C
#define SIS3302_V1410_ENERGY_START_IDX2_ALL     0x01000050
#define SIS3302_V1410_ENERGY_START_IDX3_ALL     0x01000054
#define SIS3302_V1410_ENERGY_TAU_1357           0x01000058
#define SIS3302_V1410_ENERGY_TAU_2468           0x0100005C

#define SIS3302_V1410_MCA_CALIB_PAR_1357        0x01000060
#define SIS3302_V1410_MCA_CALIB_PAR_2468        0x01000064
#define SIS3302_V1410_MCA_HISTOGRAM_PARAM_ALL   0x01000068
#define SIS3302_V1410_EVENT_CONFIG_EXTENDED_ALL 0x0100006C

/* Common definitions */

#define SIS3302_V1410_NOF_MEM_PAGES 8

/* Differences based on reduced address space */

#if defined(SIS3302_V1410_REDUCED_ADDR_SPACE)
#define SIS3302_V1410_FIRST_ADC_GROUP_OFFSET 0x00100000
#define SIS3302_V1410_NEXT_ADC_GROUP_OFFSET  0x00100000
#define SIS3302_V1410_FIRST_ADC_MEM_OFFSET   0x00400000
#define SIS3302_V1410_NEXT_ADC_MEM_OFFSET    0x00080000
#else
#define SIS3302_V1410_FIRST_ADC_GROUP_OFFSET 0x02000000
#define SIS3302_V1410_NEXT_ADC_GROUP_OFFSET  0x00800000
#define SIS3302_V1410_FIRST_ADC_MEM_OFFSET   0x04000000
#define SIS3302_V1410_NEXT_ADC_MEM_OFFSET    0x00800000
#endif

#define SIS3302_V1410_ADC_MEM(i) \
    ((SIS3302_V1410_FIRST_ADC_MEM_OFFSET)+ \
    (i)*(SIS3302_V1410_NEXT_ADC_MEM_OFFSET))

/* Event information per ADC group              */
/* addr is the address offset for each register */
/* ch is the channel number from 0 to 7         */
/* spacing is the offset to the next address    */
/* grp is the adc channel group from 0 to 4     */
#define _GROUP_3(addr,ch,spacing) (SIS3302_V1410_FIRST_ADC_GROUP_OFFSET \
            + ((ch)/2)*SIS3302_V1410_NEXT_ADC_GROUP_OFFSET \
            + (addr) \
            + ((ch)%2)*(spacing))
#define _GROUP(addr,grp) (SIS3302_V1410_FIRST_ADC_GROUP_OFFSET \
            + ((grp))*SIS3302_V1410_NEXT_ADC_GROUP_OFFSET \
            + (addr))

#define SIS3302_V1410_EVENT_CONFIG(i)           _GROUP(0x00,(i))
#define SIS3302_V1410_END_ADDRESS_THR(i)        _GROUP(0x04,(i))
#define SIS3302_V1410_PRETRIGGER_AND_GATE(i)    _GROUP(0x08,(i))
#define SIS3302_V1410_RAW_BUFFER_CONFIG(i)      _GROUP(0x0C,(i))

#define SIS3302_V1410_NEXT_SAMPLE_ADDR(i)     _GROUP_3(0x10,(i),0x4)
#define SIS3302_V1410_PRV_BNK_SAMPLE_ADDR(i)  _GROUP_3(0x18,(i),0x4)
#define SIS3302_V1410_ACTUAL_SAMPLE_VALUE(i)      _GROUP(0x20,(i))
#define SIS3302_V1410_INTERNAL_TEST(i)            _GROUP(0x24,(i))
#define SIS3302_V1410_DDR2_MEM_LOGIC_TEST(i)      _GROUP(0x28,(i))

#define SIS3302_V1410_TRG_SETUP(i)            _GROUP_3(0x30,(i),0x8)
#define SIS3302_V1410_TRG_THR(i)              _GROUP_3(0x34,(i),0x8)

#define SIS3302_V1410_ENERGY_SETUP_GP(i)        _GROUP(0x40,(i))
#define SIS3302_V1410_ENERGY_GATE_LEN(i)        _GROUP(0x44,(i))
#define SIS3302_V1410_ENERGY_SAMPLE_LEN(i)      _GROUP(0x48,(i))
#define SIS3302_V1410_ENERGY_START_IDX1(i)      _GROUP(0x4C,(i))
#define SIS3302_V1410_ENERGY_START_IDX2(i)      _GROUP(0x50,(i))
#define SIS3302_V1410_ENERGY_START_IDX3(i)      _GROUP(0x54,(i))
#define SIS3302_V1410_ENERGY_TAU(i)           _GROUP_3(0x58,(i),0x4)

#define SIS3302_V1410_MCA_CALIB_PAR(i)        _GROUP_3(0x60,(i),0x4)
#define SIS3302_V1410_MCA_HISTOGRAM_PARAM(i)  _GROUP(0x68,(i))

#define SIS3302_V1410_EVENT_CFG_EXTENDED(i)  _GROUP(0x70,(i))
#define SIS3302_V1410_TRG_EXTENDED(i)        _GROUP_3(0x78,(i),0x4)

#define SIS3302_V1410_MCA_TRG_START_COUNTER(i)  _GROUP_3(0x80,(i),0x10)
#define SIS3302_V1410_MCA_PILEUP_COUNTER(i)     _GROUP_3(0x84,(i),0x10)
#define SIS3302_V1410_MCA_OVERRANGE_COUNTER(i)  _GROUP_3(0x88,(i),0x10)
#define SIS3302_V1410_MCA_UNDERRANGE_COUNDER(i) _GROUP_3(0x8C,(i),0x10)

#define SIS3302_V1410_(i) _GROUP(0x0,(i))

#define SIS3302_V1410_FCT_CTRL_LED_ON       0x00000001
#define SIS3302_V1410_FCT_CTRL_LED_OFF      0x00010000

/* SIS3302 IRQ sources:
   0: Reached Address Threshold (edge sensitive)
   1: Reached Address Threshold (level sensitive)
*/
#define SIS3302_V1410_FCT_IRQ_CTRL_ENABLE_SRC(i)        (1 << (int)(i))
#define SIS3302_V1410_FCT_IRQ_CTRL_DISABLE_OTHER_SRC(i) (~((1 << (int)(i)) & 0xFFFF) << 16)
#define SIS3302_V1410_FCT_IRQ_CTRL_DISABLE_SRC(i)       (1 << (int)(i)+16)
#define SIS3302_V1410_FCT_IRQ_CTRL_UPDATE_IRQ           0x80000000

/* SIS3302 LEMO INPUT MODES:
        in0     in1     in2
   0:   trg     ts_clr  veto
   1:   trg     ts_clr  gate
   4:   n+1     trg     n-1
   5:   n+1     ts_clr  n-1
   6:   n+1     veto    n-1
   7:   n+1     gate    n-1
*/
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_IN_MODE_TRG_CLR_VETO 0x0
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_IN_MODE_TRG_CLR_GATE 0x1

#if defined(SIS3302_V1410_MCA_MODE)
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_OUT_MODE_TRG    0x00
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_OUT_MODE_MSCAN  0x10
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_OUT_MODE_SCAN   0x20
#else
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_OUT_MODE_ARM_BSY_TRG     0x00
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_OUT_MODE_ARM_BSYVETO_TRG 0x10
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_OUT_MODE_NP_TRG_NM       0x20
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_OUT_MODE_NP_BSYVETO_NM   0x30
#endif

/* LEMO IN i from 1 to 3 */
#define SIS3302_V1410_FCT_ACQ_CTRL_LEMO_IN_ENABLE(i) (0x800 >> (i))

/* Best use the 100_MHZ_OSC */
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_100_MHZ     0x00000000
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_50_MHZ      0x00001000
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_25_MHZ      0x00002000
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_10_MHZ      0x00003000
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_1_MHZ       0x00004000
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_100_KHZ     0x00005000
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_EXT_LEMO    0x00006000
#define SIS3302_V1410_FCT_ACQ_CTRL_CLOCK_100_MHZ_OSC 0x00007000
#define SIS3302_V1410_FCT_ACQ_CTRL_RESET             0xFFFF0000

#define SIS3302_V1410_FCT_DAC_CTRL_CMD_LOAD_SHIFT_REG 1
#define SIS3302_V1410_FCT_DAC_CTRL_CMD_LOAD_DAC       2
#define SIS3302_V1410_FCT_DAC_CTRL_CMD_CLEAR_ALL_DACS 3
#define SIS3302_V1410_FCT_DAC_CTRL_DAC_SELECT(i) ((i) << 4)

/* LNE Prescale factor := Devider - 1 */
#define SIS3302_V1410_FCT_MCA_LNE_PRESCALE_DIVIDER(i) ((i)-1)

#define SIS3302_V1410_FCT_TRG_EXT_SETUP_TRG_DECIM_MODE_OFF 0
#define SIS3302_V1410_FCT_TRG_EXT_SETUP_TRG_DECIM_MODE_2   1
#define SIS3302_V1410_FCT_TRG_EXT_SETUP_TRG_DECIM_MODE_4   2
#define SIS3302_V1410_FCT_TRG_EXT_SETUP_TRG_DECIM_MODE_8   3

#define SIS3302_V1410_FCT_ENERGY_SETUP_TRG_DECIM_MODE_OFF 0
#define SIS3302_V1410_FCT_ENERGY_SETUP_TRG_DECIM_MODE_2   1
#define SIS3302_V1410_FCT_ENERGY_SETUP_TRG_DECIM_MODE_4   2
#define SIS3302_V1410_FCT_ENERGY_SETUP_TRG_DECIM_MODE_8   3

#define SIS3302_V1410_FCT_ENERGY_TEST_MODE_MWD_TRAPEZ 0
#define SIS3302_V1410_FCT_ENERGY_TEST_MODE_MW_TRAPEZ  1
#define SIS3302_V1410_FCT_ENERGY_TEST_MODE_TRAPEZ     2
#define SIS3302_V1410_FCT_ENERGY_TEST_MODE_RESERVED   3

#define SIS3302_V1410_FCT_IRQ_CONFIG_MODE_RORA 0
#define SIS3302_V1410_FCT_IRQ_CONFIG_MODE_ROAK 1

#define SIS3302_V1410_FCT_MCA_HISTO_PARAM_SIZE_1K  0
#define SIS3302_V1410_FCT_MCA_HISTO_PARAM_SIZE_2K  1
#define SIS3302_V1410_FCT_MCA_HISTO_PARAM_SIZE_4K  2
#define SIS3302_V1410_FCT_MCA_HISTO_PARAM_SIZE_8K  3

#define SIS3302_V1410_MSK_CTRL_LED_STATUS   0x00000001
#define SIS3302_V1410_MSK_CTRL_VIPA_STATUS  0x10000000
#define SIS3302_V1410_MSK_CTRL_GEO_STATUS   0x20000000
#define SIS3302_V1410_MSK_CTRL_RED_STATUS   0x40000000
#define SIS3302_V1410_MSK_CTRL_A32_STATUS   0x80000000

#define SIS3302_V1410_MSK_FIRMWARE_MODID    0xFFFF0000
#define SIS3302_V1410_MSK_FIRMWARE_REV_MAJ  0x0000FF00
#define SIS3302_V1410_MSK_FIRMWARE_REV_MIN  0x000000FF
#define SIS3302_V1410_OFF_FIRMWARE_MODID    16
#define SIS3302_V1410_OFF_FIRMWARE_REV_MAJ  8
#define SIS3302_V1410_OFF_FIRMWARE_REV_MIN  0

#define SIS3302_V1410_MSK_IRQ_CFG_VECT 0x000000FF
#define SIS3302_V1410_MSK_IRQ_CFG_LVL  0x00000700
#define SIS3302_V1410_MSK_IRQ_CFG_ENAB 0x00000800
#define SIS3302_V1410_MSK_IRQ_CFG_MODE 0x00001000
#define SIS3302_V1410_OFF_IRQ_CFG_LVL  8
#define SIS3302_V1410_OFF_IRQ_CFG_ENAB 11
#define SIS3302_V1410_OFF_IRQ_CFG_MODE 12

#define SIS3302_V1410_MSK_IRQ_CTRL_SRC      0x000000FF
#define SIS3302_V1410_MSK_IRQ_CTRL_SRC_FLAG 0x00FF0000
#define SIS3302_V1410_MSK_IRQ_CTRL_SRC_STAT 0xFF000000
#define SIS3302_V1410_OFF_IRQ_CTRL_SRC_FLAG 16
#define SIS3302_V1410_OFF_IRQ_CTRL_SRC_STAT 24

#define SIS3302_V1410_MSK_ACQ_CTRL_LEMO_IN_MODE     0x00000007
#define SIS3302_V1410_MSK_ACQ_CTRL_MCA_ENAB         0x00000008
#define SIS3302_V1410_MSK_ACQ_CTRL_LEMO_OUT_MODE    0x00000030
#define SIS3302_V1410_MSK_ACQ_CTRL_TRG_OR_STAT      0x00000040
#define SIS3302_V1410_MSK_ACQ_CTRL_LEMO_IN_ENABLE   0x00000700
#define SIS3302_V1410_MSK_ACQ_CTRL_CLOCK_SOURCE     0x00007000
#define SIS3302_V1410_MSK_ACQ_CTRL_ARMED_BNK_1      0x00010000
#define SIS3302_V1410_MSK_ACQ_CTRL_ARMED_BNK_2      0x00020000
#define SIS3302_V1410_MSK_ACQ_CTRL_BUSY             0x00040000
#define SIS3302_V1410_MSK_ACQ_CTRL_END_ADDR_THR     0x00080000
#define SIS3302_V1410_MSK_ACQ_CTRL_MCA_BUSY         0x00100000
#define SIS3302_V1410_MSK_ACQ_CTRL_MCA_MSCAN_BUSY   0x00200000
#define SIS3302_V1410_OFF_ACQ_CTRL_LEMO_IN_MODE     0
#define SIS3302_V1410_OFF_ACQ_CTRL_MCA_ENAB         3
#define SIS3302_V1410_OFF_ACQ_CTRL_LEMO_OUT_MODE    4
#define SIS3302_V1410_OFF_ACQ_CTRL_TRG_OR_STAT      6
#define SIS3302_V1410_OFF_ACQ_CTRL_LEMO_IN_ENABLE   8
#define SIS3302_V1410_OFF_ACQ_CTRL_CLOCK_SOURCE     12
#define SIS3302_V1410_OFF_ACQ_CTRL_ARMED_BNK_1      16
#define SIS3302_V1410_OFF_ACQ_CTRL_ARMED_BNK_2      17
#define SIS3302_V1410_OFF_ACQ_CTRL_BUSY             18
#define SIS3302_V1410_OFF_ACQ_CTRL_END_ADDR_THR     19
#define SIS3302_V1410_OFF_ACQ_CTRL_MCA_BUSY         20
#define SIS3302_V1410_OFF_ACQ_CTRL_MCA_MSCAN_BUSY   21
#define SIS3302_V1410_OFF_ACQ_CTRL_LEMO_IN_DISABLE   24

#define SIS3302_V1410_MSK_MEM_PAGE          0x0000008F

#define SIS3302_V1410_MSK_DAC_CTRL_COMMAND  0x00000003
#define SIS3302_V1410_MSK_DAC_CTRL_SELECT   0x00000070
#define SIS3302_V1410_MSK_DAC_CTRL_BUSY     0x00008000
#define SIS3302_V1410_OFF_DAC_CTRL_SELECT   4

/* DAC OFFSET OF 37000 MAKES A RANGE OF -1V...+1V */
#define SIS3302_V1410_MSK_DAC_DATA_OUT_REG  0x0000FFFF
#define SIS3302_V1410_MSK_DAC_DATA_IN_REG   0xFFFF0000
#define SIS3302_V1410_OFF_DAC_DATA_IN_REG   16

#define SIS3302_V1410_MSK_MCA_SCAN_SETUP_PRESCALE 0x0fffffff
#define SIS3302_V1410_MSK_MCA_SCAN_SETUP_LNE_SRC  0x10000000

#define SIS3302_V1410_MSK_MCA_SCAN_CTRL_HIST_AUTOCLR_DISABLE 0x01
#define SIS3302_V1410_MSK_MCA_SCAN_CTRL_START_ON_BANK_2      0x10

#define SIS3302_V1410_MSK_EVENT_CFG_ODD_INVERT            0x00000001
#define SIS3302_V1410_MSK_EVENT_CFG_ODD_INT_TRG_ENAB      0x00000004
#define SIS3302_V1410_MSK_EVENT_CFG_ODD_EXT_TRG_ENAB      0x00000008
#define SIS3302_V1410_MSK_EVENT_CFG_ODD_INT_GATE_ENAB     0x00000010
#define SIS3302_V1410_MSK_EVENT_CFG_ODD_EXT_GATE_ENAB     0x00000020
#define SIS3302_V1410_MSK_EVENT_CFG_ODD_NPLUS_GATE_ENAB   0x00000040
#define SIS3302_V1410_MSK_EVENT_CFG_ODD_NMINUS_GATE_ENAB  0x00000080
#define SIS3302_V1410_MSK_EVENT_CFG_EVEN_INVERT           0x00000100
#define SIS3302_V1410_MSK_EVENT_CFG_EVEN_INT_TRG_ENAB     0x00000400
#define SIS3302_V1410_MSK_EVENT_CFG_EVEN_EXT_TRG_ENAB     0x00000800
#define SIS3302_V1410_MSK_EVENT_CFG_EVEN_INT_GATE_ENAB    0x00001000
#define SIS3302_V1410_MSK_EVENT_CFG_EVEN_EXT_GATE_ENAB    0x00002000
#define SIS3302_V1410_MSK_EVENT_CFG_EVEN_NPLUS_GATE_ENAB  0x00004000
#define SIS3302_V1410_MSK_EVENT_CFG_EVEN_NMINUS_GATE_ENAB 0x00008000
#define SIS3302_V1410_MSK_EVENT_CFG_HEADER_ID             0xFFFE0000
#define SIS3302_V1410_OFF_EVENT_CFG_HEADER_ID             17

#define SIS3302_V1410_MSK_EVENT_CFG_EXT_ODD_TRG_50KHZ      0x00000001
#define SIS3302_V1410_MSK_EVENT_CFG_EXT_ODD_NPLUS_TRG_EN   0x00000040
#define SIS3302_V1410_MSK_EVENT_CFG_EXT_ODD_NMINUS_TRG_EN  0x00000080
#define SIS3302_V1410_MSK_EVENT_CFG_EXT_EVEN_TRG_50KHZ     0x00000100
#define SIS3302_V1410_MSK_EVENT_CFG_EXT_EVEN_NPLUS_TRG_EN  0x00004000
#define SIS3302_V1410_MSK_EVENT_CFG_EXT_EVEN_NMINUS_TRG_EN 0x00008000

#define SIS3302_V1410_MSK_END_ADDR_THR          0x00FFFFFC

#define SIS3302_V1410_MSK_TRG_GATE_LEN          0x0000FFFF
#define SIS3302_V1410_MSK_PRETRIGGER_DELAY      0x03FF0000
#define SIS3302_V1410_OFF_PRETRIGGER_DELAY      16

#define SIS3302_V1410_MSK_RAW_BUF_START_IDX     0x0000FFFE
#define SIS3302_V1410_MSK_RAW_BUF_SAMPLE_LEN    0xFFFC0000
#define SIS3302_V1410_OFF_RAW_BUF_SAMPLE_LEN    16

#define SIS3302_V1410_MSK_NEXT_SAMPLE_ADDR      0x00FFFFFC
#define SIS3302_V1410_MSK_PREV_BANK_SAMPLE_ADDR 0x00FFFFFC
#define SIS3302_V1410_MSK_NEXT_SAMPLE_BANK_FLAG 0x01000000
#define SIS3302_V1410_OFF_NEXT_SAMPLE_BANK_FLAG 24

#define SIS3302_V1410_MSK_ACTUAL_SAMPLE_ODD     0xFFFF0000
#define SIS3302_V1410_OFF_ACTUAL_SAMPLE_ODD     16
#define SIS3302_V1410_MSK_ACTUAL_SAMPLE_EVEN    0x0000FFFF

#define SIS3302_V1410_MSK_TRG_SETUP_PEAK_TIME   0x000000FF
#define SIS3302_V1410_MSK_TRG_SETUP_SUMG_TIME   0x0000FF00
#define SIS3302_V1410_MSK_TRG_SETUP_PULSE_LEN   0x00FF0000
#define SIS3302_V1410_MSK_TRG_SETUP_GATE_LEN    0x3F000000
#define SIS3302_V1410_OFF_TRG_SETUP_SUMG_TIME   8
#define SIS3302_V1410_OFF_TRG_SETUP_PULSE_LEN   16
#define SIS3302_V1410_OFF_TRG_SETUP_GATE_LEN    24

#define SIS3302_V1410_MSK_TRG_EXT_SETUP_PEAK_89     0x00000003
#define SIS3302_V1410_MSK_TRG_EXT_SETUP_SUMG_89     0x00000300
#define SIS3302_V1410_MSK_TRG_EXT_SETUP_TRG_DECIM   0x00030000
#define SIS3302_V1410_MSK_TRG_EXT_SETUP_TRG_DELAY   0x1F000000
#define SIS3302_V1410_OFF_TRG_EXT_SETUP_SUMG_89     8
#define SIS3302_V1410_OFF_TRG_EXT_SETUP_TRG_DECIM   16
#define SIS3302_V1410_OFF_TRG_EXT_SETUP_TRG_DELAY   24

/* Example:
   PEAK_TIME = 10 -> data gets shifted right by 4
   SUMG_TIME = 16 (time between sums)
   GT/ENABLE is ON
   THR_VALUE = 100 + 0x10000 (constant must be added)

   actual sum value:
     asv = (100 << 4), because of former right shift
   actual trigger threshold:
     att = asv / 10, because of summing of 10 samples

   -> att = 160 adc counts ~5 mV
*/
#define SIS3302_V1410_MSK_TRG_THR_VALUE         0x0001FFFF
#define SIS3302_V1410_MSK_TRG_THR_MODE_GT       0x02000000
#define SIS3302_V1410_MSK_TRG_ENABLE            0x02000000
#define SIS3302_V1410_MSK_TRG_THR_DISABLE_OUT   0x04000000
#define SIS3302_V1410_OFF_TRG_THR_MODE_GT       25
#define SIS3302_V1410_OFF_TRG_ENABLE            25
#define SIS3302_V1410_OFF_TRG_THR_DISABLE_OUT   26

#define SIS3302_V1410_TRG_THR_ADDED_CONST       0x10000

#define SIS3302_V1410_MSK_ENERGY_SETUP_PEAK         0x000300FF
#define SIS3302_V1410_MSK_ENERGY_SETUP_SUMG         0x0000FF00
#define SIS3302_V1410_MSK_ENERGY_SETUP_DECIM        0x30000000
#define SIS3302_V1410_MSK_ENERGY_SETUP_EXTRA_FILTER 0x40000000
#define SIS3302_V1410_OFF_ENERGY_SETUP_SUMG         8
#define SIS3302_V1410_OFF_ENERGY_SETUP_PEAK_89      16
#define SIS3302_V1410_OFF_ENERGY_SETUP_DECIM        28
#define SIS3302_V1410_OFF_ENERGY_SETUP_EXTRA_FILTER 30

#define SIS3302_V1410_MSK_ENERGY_GATE_LEN  0x0000FFFF
#define SIS3302_V1410_MSK_ENERGY_TEST_MODE 0x03000000
#define SIS3302_V1410_OFF_ENERGY_TEST_MODE 28

#define SIS3302_V1410_MSK_ENERGY_SAMPLE_LEN        0x000003FF
#define SIS3302_V1410_MSK_ENERGY_SAMPLE_START_IDX  0x0000FFFF
#define SIS3302_V1410_MSK_ENERGY_TAU               0x0000003F

/* Note: Divider must not be 0.
   Example: 100 mV Signal -> 3000 counts with PEAK_TIME=100
            -> Energy value: 300000
*/
#define SIS3302_V1410_MSK_MCA_CALIB_SUB_OFFSET          0x000FFFFF
#define SIS3302_V1410_MSK_MCA_CALIB_MULTI_ENABLE        0x0FF00000
#define SIS3302_V1410_MSK_MCA_CALIB_DIVIDER             0xF0000000
#define SIS3302_V1410_OFF_MCA_CALIB_MULTI_ENABLE        20
#define SIS3302_V1410_OFF_MCA_CALIB_DIVIDER             28

#define SIS3302_V1410_MSK_MCA_HISTO_PARAM_SIZE          0x00000003
#define SIS3302_V1410_MSK_MCA_HISTO_PARAM_PILEUP_ALLOW  0x00000008
#define SIS3302_V1410_MSK_MCA_HISTO_PARAM_ODD_ENABLE    0x00000010
#define SIS3302_V1410_MSK_MCA_HISTO_PARAM_EVEN_ENABLE   0x00000020
#define SIS3302_V1410_MSK_MCA_HISTO_PARAM_TEST_MODE     0x00000080

#define SIS3302_V1410_MCA_CALIB_FULL_ADC_RANGE_1K       0x68000000
#define SIS3302_V1410_MCA_CALIB_FULL_ADC_RANGE_2K       0x58000000
#define SIS3302_V1410_MCA_CALIB_FULL_ADC_RANGE_4K       0x48000000
#define SIS3302_V1410_MCA_CALIB_FULL_ADC_RANGE_8K       0x38000000

#if defined(SIS3302_V1410_MCA_MODE)
/* Histogram memory layout:
   Histograms are directly stored in memory one after another,
   if MCA scan is enabled.
   Histogram 0: Start 0x0
   Histogram 1: Start 0x0 + 1 * number_of_bins
   Histogram N: Start 0x0 + N * number_of_bins
   ...
*/
#else
/* Event buffer layout (words):
   0: Timestamp 47_32 and Event Header and ADC_ID
   1: Timestamp 31_0
   2: ADC RAW Buffer (up to 32k Words)
   3: Energy data buffer (up to 510 Words)
   4: Energy max value
   5: Energy value from first value of Energy Gate
   6: Pileup, Retrigger, Trigger counter
   7: Trailer
*/
#define SIS3302_V1410_MSK_EVENT_BUF_TS_HI   0xFFFF0000
#define SIS3302_V1410_MSK_EVENT_BUF_TS_MID  0xFFFF0000
#define SIS3302_V1410_MSK_EVENT_BUF_TS_LOW  0x0000FFFF
#define SIS3302_V1410_OFF_EVENT_BUF_TS_HI   16
#define SIS3302_V1410_OFF_EVENT_BUF_TS_MID  16

/* Fast trigger count is incremented during active trg gate */
/* Pileup flag is set, when fast trigger counter > 1 */
/* Retrigger flag is set, if an earlier fast trigger
   happened before the actual fast trigger.
    t_early = ((P+G)*Decimation) * clockcycles + t_fastTrg
   In this case the Energy Filter contains "Energy" of
   earlier fast trigger
*/
#define SIS3302_V1410_MSK_EVENT_BUF_TRG_FLAG        0x00000001
#define SIS3302_V1410_MSK_EVENT_BUF_FAST_TRG_CNT    0x0F000000
#define SIS3302_V1410_MSK_EVENT_BUF_NMINUS_TRG_FLAG 0x10000000
#define SIS3302_V1410_MSK_EVENT_BUF_NPLUS_TRG_FLAG  0x20000000
#define SIS3302_V1410_MSK_EVENT_BUF_RETRIG_FLAG     0x40000000
#define SIS3302_V1410_MSK_EVENT_BUF_PILEUP_FLAG     0x80000000
#define SIS3302_V1410_OFF_EVENT_BUF_FAST_TRG_CNT    24
#define SIS3302_V1410_OFF_EVENT_BUF_RETRIG_FLAG     30
#define SIS3302_V1410_OFF_EVENT_BUF_PILEUP_FLAG     31
#define SIS3302_V1410_MSK_EVENT_BUF_HEADER          0x0000FFFF /*TODO*/
#define SIS3302_V1410_MSK_EVENT_BUF_RAW_LOW         0x0000FFFF
#define SIS3302_V1410_MSK_EVENT_BUF_RAW_HIGH        0xFFFF0000
#define SIS3302_V1410_MSK_EVENT_BUF_TRAILER         0xDEADBEEF
#define SIS3302_V1410_OFF_EVENT_BUF_RAW_HIGH        16
#endif


// Structs

typedef union {
    struct {
        uint32_t addr    :25;
        uint32_t unused2 :3;
        uint32_t wrap    :1;
        uint32_t trigger :1;
        uint32_t unused  :2;
    };
    uint32_t data;
} EventDirEntry_t;

typedef union {
    struct {
        uint32_t high;
        uint32_t low;
    };
    uint32_t data[2];
    uint64_t data64;
} TimestampDir_t;

typedef union {
    struct {
        uint32_t high   :16;    // Not quite sure about this order
        uint32_t low    :16;
    };
    uint32_t data;
} DataStruct_t;


#endif
