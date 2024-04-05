# efi

## UEFI headers

To build correctly, you have to set the ```EFI_PLATFORM``` variable on the ```cc``` command line:
```cc EFI_PLATFORM=1``` would use the X64 architecture. The allowed values are defined in efi.h:

```c
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
```

These headers are currently incomplete and you should probably use the official headers from [Tianocore](https://www.tianocore.org/).

You could build a "Hello World" application just by including <efi.h> and using the declarations there. Everything needed to reference the *Boot Services*, *Runtime Services*, *Configuration Table*, *System Table* and base types are included in <efi.h>.

Using protocols requires including the appropriate protocol header. The naming convention for the include filename is to use the name of the structure, as it appears in the UEFI specification, and naming the file using the first letter of each component of the structure name. For example, the *EfiGraphicsOutputProtocol* is defined in *protocol/efi-gop.h*.

Please let me know of any mistakes. I'm also willing to add things as a favor. As it stands, I've only included components that I'm actually using.

### Headers

#### EFI Base

* ```efi-bs.h``` *boot services*
* ```efi-ct.h``` *configuration table*
* ```efi.h``` *base system*
* ```efi-rs.h``` *runtime services*
* ```efi-st.h``` *system table*

#### EFI Protocols

* ```efi-time.h``` *time representation protocol*
* ```protocol/efi-acpitp.h``` *acpi table protocol*
* ```protocol/efi-dpp.h``` *device path protocol*
* ```protocol/efi-fp.h``` *file protocol*
* ```protocol/efi-gop.h``` *graphics output protocol*
* ```protocol/efi-lidpp.h``` *loaded image device path protocol*
* ```protocol/efi-lip.h``` *loaded image protocol*
* ```protocol/efi-sfsp.h``` *simple file system protocol*
* ```protocol/efi-stip.h``` *simple text input protocol*
* ```protocol/efi-stop.h``` *simple text output protocol*
