/**
 * @file efi-time.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief UEFI time representation.
 * @version 0.2.0
 * @date 2024-04-04
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_TIME_H
#define _EFI_TIME_H

#include <efi.h>

#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02

#define EFI_UNSPECIFIED_TIMEZONE 0x07ff

typedef struct EFI_TIME {
    UINT16 Year;
    UINT8 Month;
    UINT8 Day;
    UINT8 Hour;
    UINT8 Minute;
    UINT8 Second;
    UINT8 Pad1;
    UINT32 Nanosecond;
    INT16 TimeZone;
    UINT8 Daylight;
    UINT8 PAD2;
} EFI_TIME;

typedef struct EFI_TIME_CAPABILITIES {
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

#endif // _EFI_TIME_H
