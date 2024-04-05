/**
 * @file efi-stip.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief UEFI Simple Text Input Protocol.
 * @version 0.2.0
 * @date 2024-04-04
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_STIP_H
#define _EFI_STIP_H

#include <efi.h>

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID {0x387477c1, 0x69c7, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}

typedef struct EFI_INPUT_KEY {
    UINT16 ScanCode;
    CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_INPUT_RESET)(IN struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, IN BOOLEAN ExtendedVerification);
typedef EFI_STATUS (EFIAPI *EFI_INPUT_READ_KEY)(IN struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, OUT EFI_INPUT_KEY *Key);

typedef struct EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
    EFI_INPUT_RESET Reset;
    EFI_INPUT_READ_KEY ReadKeyStroke;
    EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

#endif // _EFI_STIP_H
