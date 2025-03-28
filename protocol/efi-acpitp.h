/**
 * @file efi-acpitp.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief UEFI ACPI table protocol.
 * @version 0.1
 * @date 2024-04-04
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_ACPITP_H
#define _EFI_ACPITP_H

#include <efi.h>

#define EFI_ACPI_TABLE_PROTOCOL_GUID {0xffe06bdd, 0x6107, 0x46a6, {0x7b, 0xb2, 0x5a, 0x9c, 0x7e, 0xc5, 0x28, 0x5c}}

struct EFI_ACPI_TABLE_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_ACPI_TABLE_INSTALL_ACPI_TABLE)(IN struct EFI_ACPI_TABLE_PROTOCOL *This, IN VOID *AcpiTableBuffer, IN UINTN AcpiTableBufferSize, OUT UINTN *TableKey);
typedef EFI_STATUS (EFIAPI *EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE)(IN struct EFI_ACPI_TABLE_PROTOCOL *This, IN UINTN  TableKey);

typedef struct EFI_ACPI_TABLE_PROTOCOL {
    EFI_ACPI_TABLE_INSTALL_ACPI_TABLE InstallAcpiTable;
    EFI_ACPI_TABLE_UNINSTALL_ACPI_TABLE UninstallAcpiTable;
} EFI_ACPI_TABLE_PROTOCOL;

#endif // _EFI_ACPITP_H
