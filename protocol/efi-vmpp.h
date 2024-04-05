/**
 * @file efi-vmpp.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief UEFI VGA Mini Port Protocol
 * @version 0.2.0
 * @date 2024-04-04
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_VMPP_H
#define _EFI_VMPP_H

#include <efi.h>

#define EFI_VGA_MINI_PORT_PROTOCOL_GUID {0xc7735a2f, 0x88f5, 0x4882, {0xae, 0x63, 0xfa, 0xac, 0x8c, 0x8b, 0x86, 0xb3}}

struct EFI_VGA_MINI_PORT_PROTOCOL;

typedef EFI_STATUS (*EFI_VGA_MINI_PORT_SET_MODE)(
    IN EFI_VGA_MINI_PORT_PROTOCOL *This, 
    IN UINTN ModeNumber);

typedef struct EFI_VGA_MINI_PORT_PROTOCOL {
    EFI_VGA_MINI_PORT_SET_MODE SetMode;
    UINT64 VgaMemoryOffset;
    UINT64 CrtcAddressRegisterOffset;
    UINT64 CrtcDataRegisterOffset;
    UINT8 VgaMemoryBar;
    UINT8 CrtcAddressRegisterBar;
    UINT8 CrtcDataRegisterBar;
    UINT8 MaxMode;
} EFI_VGA_MINI_PORT_PROTOCOL;

#endif // _EFI_VMPP_H
