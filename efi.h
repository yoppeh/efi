/**
 * @file efi.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief UEFI basic types and constants.
 * @version 0.2.0
 * @date 2024-04-03
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_H
#define _EFI_H

#include <stdint.h>

#define EFI_ARCH_IA32 0
#define EFI_ARCH_X64 1
#define EFI_ARCH_ITANIUM 2
#define EFI_ARCH_AARCH32 3
#define EFI_ARCH_AARCH64 4
#define EFI_ARCH_RISCV32 5
#define EFI_ARCH_RISCV64 6
#define EFI_ARCH_RISCV128 7
#define EFI_ARCH_LOONGARCH32 8
#define EFI_ARCH_LOONGARCH64 9

#if EFI_PLATFORM == EFI_ARCH_IA32
#define EFI_WORD_SIZE 32
#elif EFI_PLATFORM == EFI_ARCH_X64
#define EFI_WORD_SIZE 64
#elif EFI_PLATFORM == EFI_ARCH_ITANIUM
#define EFI_WORD_SIZE 64
#elif EFI_PLATFORM == EFI_ARCH_AARCH32
#define EFI_WORD_SIZE 32
#elif EFI_PLATFORM == EFI_ARCH_AARCH64
#define EFI_WORD_SIZE 64
#elif EFI_PLATFORM == EFI_ARCH_RISCV32
#define EFI_WORD_SIZE 32
#elif EFI_PLATFORM == EFI_ARCH_RISCV64
#define EFI_WORD_SIZE 64
#elif EFI_PLATFORM == EFI_ARCH_RISCV128
#define EFI_WORD_SIZE 128
#elif EFI_PLATFORM == EFI_ARCH_LOONGARCH32
#define EFI_WORD_SIZE 32
#elif EFI_PLATFORM == EFI_ARCH_LOONGARCH64
#define EFI_WORD_SIZE 64
#else
#error "EFI_PLATFORM not defined."
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#ifndef CONST
#define CONST
#endif

#ifndef EFIAPI
#define EFIAPI
#endif

#define EFI_FALSE (0 == 1)
#define EFI_TRUE (1 == 1)

#define EFI_SUCCESS 0
#define EFI_WARN_MASK 0
#define EFI_WARN_PIAS_MASK (0x2 << (EFI_WORD_SIZE - 4))
#define EFI_WARN_OEM_MASK (0x4 << (EFI_WORD_SIZE - 4))
#define EFI_ERR_MASK (0x8 << (EFI_WORD_SIZE - 4))
#define EFI_ERR_PIAS_MASK (0xa << (EFI_WORD_SIZE - 4))
#define EFI_ERR_OEM_MASK (0xc << (EFI_WORD_SIZE - 4))

#define EFI_LOAD_ERROR 1
#define EFI_INVALID_PARAMETER 2
#define EFI_UNSUPPORTED 3
#define EFI_BAD_BUFFER_SIZE 4
#define EFI_BUFFER_TOO_SMALL 5
#define EFI_NOT_READY 6
#define EFI_DEVICE_ERROR 7
#define EFI_WRITE_PROTECTED 8
#define EFI_OUT_OF_RESOURCES 9
#define EFI_VOLUME_CORRUPTED 10
#define EFI_VOLUME_FULL 11
#define EFI_NO_MEDIA 12
#define EFI_MEDIA_CHANGED 13
#define EFI_NOT_FOUND 14
#define EFI_ACCESS_DENIED 15
#define EFI_NO_RESPONSE 16
#define EFI_NO_MAPPING 17
#define EFI_TIMEOUT 18
#define EFI_NOT_STARTED 19
#define EFI_ALREADY_STARTED 20
#define EFI_ABORTED 21
#define EFI_ICMP_ERROR 22
#define EFI_TFTP_ERROR 23
#define EFI_PROTOCOL_ERROR 24
#define EFI_INCOMPATIBLE_VERSION 25
#define EFI_SECURITY_VIOLATION 26
#define EFI_CRC_ERROR 27
#define EFI_END_OF_MEDIA 28
#define EFI_END_OF_FILE 31
#define EFI_INVALID_LANGUAGE 32
#define EFI_COMPROMISED_DATA 33
#define EFI_IP_ADDRESS_CONFLICT 34
#define EFI_HTTP_ERROR 35

#define EFI_WARN_UNKNOWN_GLYPH 1
#define EFI_WARN_DELETE_FAILURE 2
#define EFI_WARN_WRITE_FAILURE 3
#define EFI_WARN_BUFFER_TOO_SMALL 4
#define EFI_WARN_STALE_DATA 5
#define EFI_WARN_FILE_SYSTEM 6
#define EFI_WARN_RESET_REQUIRED 7

#define EFI_MEMORY_UC 0x0000000000000001
#define EFI_MEMORY_WC 0x0000000000000002
#define EFI_MEMORY_WT 0x0000000000000004
#define EFI_MEMORY_WB 0x0000000000000008
#define EFI_MEMORY_UCE 0x0000000000000010
#define EFI_MEMORY_WP 0x0000000000001000
#define EFI_MEMORY_RP 0x0000000000002000
#define EFI_MEMORY_XP 0x0000000000004000
#define EFI_MEMORY_NV 0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 0x0000000000010000
#define EFI_MEMORY_RO 0x0000000000020000
#define EFI_MEMORY_SP 0x0000000000040000
#define EFI_MEMORY_CPU_CRYPTO 0x0000000000080000
#define EFI_MEMORY_RUNTIME 0x8000000000000000
#define EFI_MEMORY_ISA_VALID 0x4000000000000000
#define EFI_MEMORY_ISA_MASK 0x0ffff00000000000

typedef void VOID;
typedef uint8_t BOOLEAN;
typedef uint8_t CHAR8;
typedef uint16_t CHAR16;
typedef VOID *EFI_EVENT;
typedef VOID *EFI_HANDLE;
typedef uint64_t EFI_LBA;
typedef uint64_t EFI_PHYSICAL_ADDRESS;
typedef uint64_t EFI_STATUS;
typedef uint64_t EFI_TL;
typedef uint64_t EFI_TPL;
typedef uint64_t EFI_VIRTUAL_ADDRESS;
typedef int8_t INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int64_t INT64;
typedef struct INT128 {
    int64_t lo;
    int64_t hi;
} INT128;
#if EFI_WORD_SIZE == 32
typedef int32_t INTN;
#elif EFI_WORD_SIZE == 64
typedef int64_t INTN;
#elif EFI_WORD_SIZE == 128
typedef INT128 INTN;
#endif
typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef INT128 UINT128;
#if EFI_WORD_SIZE == 32
typedef uint32_t UINTN;
#elif EFI_WORD_SIZE == 64
typedef uint64_t UINTN;
#elif EFI_WORD_SIZE == 128
typedef INT128 UINTN;
#endif
typedef uint32_t EFI_IPv4_ADDRESS;
typedef uint8_t EFI_IPv6_ADDRESS[16];
typedef union {
    UINT32 Addr[4];
    EFI_IPv4_ADDRESS v4;
    EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;
typedef uint8_t EFI_MAC_ADDRESS[32];

typedef struct EFI_GUID {
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_GUID;

typedef struct EFI_MEMORY_DESCRIPTOR {
    UINT32 Type;
    EFI_PHYSICAL_ADDRESS PhysicalStart;
    EFI_VIRTUAL_ADDRESS VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
} EFI_MEMORY_DESCRIPTOR;

typedef struct EFI_TABLE_HEADER {
    UINT64 Signature;  
    UINT32 Revision;   
    UINT32 HeaderSize; 
    UINT32 CRC32;      
    UINT32 Reserved;
} EFI_TABLE_HEADER;

#include <efi-st.h>

#endif // _EFI_H
