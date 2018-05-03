/*
 * efi-dpp.h
 *
 * UEFI device path protocol.
 */

#ifndef __EFI_DPP_H
#define __EFI_DPP_H


#define EFI_DEVICE_PATH_PROTOCOL_GUID   {0x09576e91, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}


typedef struct EFI_DEVICE_PATH_PROTOCOL {
    UINT8   Type;
    UINT8   SubType;
    UINT8   Length[2];
} EFI_DEVICE_PATH_PROTOCOL;


#endif /* __EFI_DPP_H */
