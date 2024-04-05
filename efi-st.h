/**
 * @file efi-st.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief EFI System Table.
 * @version 0.2.0
 * @date 2024-04-04
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_ST_H
#define _EFI_ST_H

#include <efi.h>
#include <protocol/efi-stip.h>
#include <protocol/efi-stop.h>
#include <efi-rs.h>
#include <efi-bs.h>
#include <efi-ct.h>

typedef struct EFI_SYSTEM_TABLE {
    EFI_TABLE_HEADER Hdr;
    CHAR16 *FirmwareVendor;
    UINT32 FirmwareRevision;
    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;
    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;
    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;

#endif // _EFI_ST_H
