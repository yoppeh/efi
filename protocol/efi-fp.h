/**
 * @file efi-fp.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief UEFI File Protocol.
 * @version 0.2.0
 * @date 2024-04-04
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_FP_H
#define _EFI_FP_H

#include <efi.h>

#define EFI_FILE_INFO_ID {0x09576e92, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}
#define EFI_FILE_SYSTEM_INFO_ID {0x09576e93, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}} 
#define EFI_FILE_SYSTEM_VOLUME_LABEL_ID {0xdb47d7d3, 0xfe81, 0x11d3, {0x9a, 0x35, 0x00, 0x90, 0x27, 0x3f, 0xc1, 0x4d}}

#define EFI_FILE_PROTOCOL_REVISION 0x00010000
#define EFI_FILE_PROTOCOL_REVISION2 0x00020000
#define EFI_FILE_PROTOCOL_LATEST_REVISION EFI_FILE_PROTOCOL_REVISION2

#define EFI_FILE_MODE_READ 0x0000000000000001
#define EFI_FILE_MODE_WRITE 0x0000000000000002
#define EFI_FILE_MODE_CREATE 0x8000000000000000

#define EFI_FILE_READ_ONLY 0x0000000000000001
#define EFI_FILE_HIDDEN 0x0000000000000002
#define EFI_FILE_SYSTEM 0x0000000000000004
#define EFI_FILE_RESERVED 0x0000000000000008
#define EFI_FILE_DIRECTORY 0x0000000000000010
#define EFI_FILE_ARCHIVE 0x0000000000000020
#define EFI_FILE_VALID_ATTR 0x0000000000000037

typedef struct EFI_FILE_INFO {
    UINT64 Size;
    UINT64 FileSize;
    UINT64 PhysicalSize;
    EFI_TIME CreateTime;
    EFI_TIME LastAccessTime;
    EFI_TIME ModificationTime;
    UINT64 Attribute;
    CHAR16 FileName[];
} EFI_FILE_INFO;

typedef struct EFI_FILE_SYSTEM_INFO {
    UINT64 Size;
    BOOLEAN ReadOnly;
    UINT64 VolumeSize;
    UINT64 FreeSpace;
    UINT32 BlockSize;
    CHAR16 VolumeLabel;
} EFI_FILE_SYSTEM_INFO;

typedef struct EFI_FILE_SYSTEM_VOLUME_LABEL {
    CHAR16 VolumeLabel[];
} EFI_FILE_SYSTEM_VOLUME_LABEL;

typedef struct EFI_FILE_IO_TOKEN {
    EFI_EVENT Event;
    EFI_STATUS Status;
    UINTN BufferSize;
    VOID *Buffer;
} EFI_FILE_IO_TOKEN;

struct EFI_FILE_PROTOCOL;

typedef EFI_STATUS (EFIAPI *EFI_FILE_OPEN)(IN struct EFI_FILE_PROTOCOL *This, OUT struct EFI_FILE_PROTOCOL **NewHandle, IN CHAR16 *FileName, IN UINT64 OpenMode, IN UINT64 Attributes);
typedef EFI_STATUS (EFIAPI *EFI_FILE_CLOSE)(IN struct EFI_FILE_PROTOCOL *This);
typedef EFI_STATUS (EFIAPI *EFI_FILE_DELETE)(IN struct EFI_FILE_PROTOCOL *This);
typedef EFI_STATUS (EFIAPI *EFI_FILE_READ)(IN struct EFI_FILE_PROTOCOL *This, IN OUT UINTN *BufferSize, OUT VOID *Buffer);
typedef EFI_STATUS (EFIAPI *EFI_FILE_WRITE)(IN struct EFI_FILE_PROTOCOL *This, IN OUT UINTN *BufferSize, IN VOID *Buffer);
typedef EFI_STATUS (EFIAPI *EFI_FILE_OPEN_EX)(IN struct EFI_FILE_PROTOCOL *This, OUT struct EFI_FILE_PROTOCOL **NewHandle, IN CHAR16 *FileName, IN UINT64 OpenMode, IN UINT64 Attributes, IN OUT EFI_FILE_IO_TOKEN *Token);
typedef EFI_STATUS (EFIAPI *EFI_FILE_READ_EX)(IN struct EFI_FILE_PROTOCOL *This, IN OUT EFI_FILE_IO_TOKEN *Token);
typedef EFI_STATUS (EFIAPI *EFI_FILE_WRITE_EX)(IN struct EFI_FILE_PROTOCOL *This, IN OUT EFI_FILE_IO_TOKEN *Token);
typedef EFI_STATUS (EFIAPI *EFI_FILE_FLUSH_EX)(IN struct EFI_FILE_PROTOCOL *This, IN EFI_FILE_IO_TOKEN *Token);
typedef EFI_STATUS (EFIAPI *EFI_FILE_SET_POSITION)(IN struct EFI_FILE_PROTOCOL *This, IN UINT64 Position);
typedef EFI_STATUS (EFIAPI *EFI_FILE_GET_POSITION)(IN struct EFI_FILE_PROTOCOL *This, OUT UINT64 *Position);
typedef EFI_STATUS (EFIAPI *EFI_FILE_GET_INFO)(IN struct EFI_FILE_PROTOCOL *This, IN EFI_GUID *InformationType, IN OUT UINTN *BufferSize, OUT VOID *Buffer);
typedef EFI_STATUS (EFIAPI *EFI_FILE_SET_INFO)(IN struct EFI_FILE_PROTOCOL *This, IN EFI_GUID *InformationType, IN UINTN BufferSize, IN VOID *Buffer);
typedef EFI_STATUS (EFIAPI *EFI_FILE_FLUSH)(IN struct EFI_FILE_PROTOCOL *This);

typedef struct EFI_FILE_PROTOCOL {
    UINT64 Revision;
    EFI_FILE_OPEN Open;
    EFI_FILE_CLOSE Close;
    EFI_FILE_DELETE Delete;
    EFI_FILE_READ Read;
    EFI_FILE_WRITE Write;
    EFI_FILE_GET_POSITION GetPosition;
    EFI_FILE_SET_POSITION SetPosition;
    EFI_FILE_GET_INFO GetInfo;
    EFI_FILE_SET_INFO SetInfo;
    EFI_FILE_FLUSH Flush;
    EFI_FILE_OPEN_EX OpenEx;
    EFI_FILE_READ_EX ReadEx;
    EFI_FILE_WRITE_EX WriteEx;
    EFI_FILE_FLUSH_EX FlushEx;
} EFI_FILE_PROTOCOL;

#endif // _EFI_FP_H
