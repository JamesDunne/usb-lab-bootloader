/*********************************************************************
 *
 *                Microchip USB C18 Firmware 
 *
 *********************************************************************
 * FileName:        io_cfg.h
 * Dependencies:    See INCLUDES section below
 * Processor:       PIC18
 * Compiler:        C18 3.11+
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * File Version  Date		Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 1.0			 04/09/2008	Started from MCHPFSUSB v1.3 HID Mouse
 *							demo project.  Commented out items that
 *							are not particularly useful for the
 *							bootloader.
 ********************************************************************/

#ifndef IO_CFG_H
#define IO_CFG_H

/** I N C L U D E S *************************************************/
#include "usbcfg.h"

/** T R I S *********************************************************/
#define INPUT_PIN           1
#define OUTPUT_PIN          0

#if defined(PIC18F4550_PICDEM_FS_USB)
/** U S B ***********************************************************/
#define tris_usb_bus_sense  TRISAbits.TRISA1    // Input

#if defined(USE_USB_BUS_SENSE_IO)
#define usb_bus_sense       PORTAbits.RA1
#else
#define usb_bus_sense       1
#endif

#define tris_self_power     TRISAbits.TRISA2    // Input

#if defined(USE_SELF_POWER_SENSE_IO)
#define self_power          PORTAbits.RA2
#else
#define self_power          1
#endif

// External Transceiver Interface
#define tris_usb_vpo        TRISBbits.TRISB3    // Output
#define tris_usb_vmo        TRISBbits.TRISB2    // Output
#define tris_usb_rcv        TRISAbits.TRISA4    // Input
#define tris_usb_vp         TRISCbits.TRISC5    // Input
#define tris_usb_vm         TRISCbits.TRISC4    // Input
#define tris_usb_oe         TRISCbits.TRISC1    // Output

#define tris_usb_suspnd     TRISAbits.TRISA3    // Output

/** L E D ***********************************************************/
#define mInitAllLEDs()      LATC &= 0b11111100; TRISC &= 0b11111100;

#define mLED_1              LATCbits.LATC0
#define mLED_2              LATCbits.LATC1

#define mLED_1_On()         mLED_1 = 1;
#define mLED_2_On()         mLED_2 = 1;

#define mLED_1_Off()        mLED_1 = 0;
#define mLED_2_Off()        mLED_2 = 0;

#define mLED_1_Toggle()     mLED_1 = !mLED_1;
#define mLED_2_Toggle()     mLED_2 = !mLED_2;

/** S W I T C H *****************************************************/
#define mInitAllSwitches()  TRISEbits.TRISE3=1;
#define mInitSwitch2()      TRISEbits.TRISE3=1;
#define sw2                 PORTEbits.RE3 //MCLR button on USBPICBOARD1.0

/** P O T ***********************************************************/
#define mInitPOT()          TRISAbits.TRISA0=1;ADCON0=0x01;ADCON2=0x3C;

/** S P I : Chip Select Lines ***************************************/
#define tris_cs_temp_sensor TRISBbits.TRISB2    // Output
#define cs_temp_sensor      LATBbits.LATB2

#define tris_cs_sdmmc       TRISBbits.TRISB3    // Output
#define cs_sdmmc            LATBbits.LATB3

/** S D M M C *******************************************************/
#define TRIS_CARD_DETECT    TRISBbits.TRISB4    // Input
#define CARD_DETECT         PORTBbits.RB4

#define TRIS_WRITE_DETECT   TRISAbits.TRISA4    // Input
#define WRITE_DETECT        PORTAbits.RA4

/********************************************************************/
/********************************************************************/
/********************************************************************/

#else
    #error Not a supported board (yet), add I/O pin mapping in __FILE__, line __LINE__
#endif

#endif //IO_CFG_H
