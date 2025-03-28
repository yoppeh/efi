/**
 * @file efi-dpp.h
 * @author Warren Mann (warren@nonvol.io)
 * @brief UEFI Device Path Protocol.
 * @version 0.2.0
 * @date 2024-04-04
 * @copyright Copyright (c) 2024
 */

#ifndef _EFI_DPP_H
#define _EFI_DPP_H

#include <efi.h>

#define EFI_DEVICE_PATH_PROTOCOL_GUID {0x09576e91, 0x6d3f, 0x11d2, {0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b}}

#define EFI_HARDWARE_DEVICE_PATH_TYPE 0x01
#define EFI_ACPI_DEVICE_PATH_TYPE 0x02
#define EFI_MESSAGING_DEVICE_PATH_TYPE 0x03
#define EFI_MEDIA_DEVICE_PATH_TYPE 0x04
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_PATH_TYPE 0x05
#define EFI_END_OF_HARDWARE_DEVICE_PATH_TYPE 0x7f

#define EFI_END_ENTIRE_DEVICE_PATH_SUBTYPE 0xff
#define EFI_END_INSTANCE_DEVICE_PATH_SUBTYPE 0x01

#define EFI_DEVICE_PATH_SUBTYPE_PCI 0x01
#define EFI_DEVICE_PATH_SUBTYPE_PCCARD 0x02
#define EFI_DEVICE_PATH_SUBTYPE_MEMMAP 0x03
#define EFI_DEVICE_PATH_SUBTYPE_VENDOR 0x04
#define EFI_DEVICE_PATH_SUBTYPE_CONTROLLER 0x05
#define EFI_DEVICE_PATH_SUBTYPE_BMC 0x06

#define EFI_DEVICE_PATH_SUBTYPE_ACPI 0x01
#define EFI_DEVICE_PATH_SUBTYPE_EXPANDED_ACPI 0x02
#define EFI_DEVICE_PATH_SUBTYPE_ADR 0x03
#define EFI_DEVICE_PATH_SUBTYPE_NVDIMM 0x04

#define EFI_DEVICE_PATH_SUBTYPE_ATAPI 0x01
#define EFI_DEVICE_PATH_SUBTYPE_SCSI 0x02
#define EFI_DEVICE_PATH_SUBTYPE_FIBRECHANNEL 0x03
#define EFI_DEVICE_PATH_SUBTYPE_FIBRECHANNEL_EX 0x15
#define EFI_DEVICE_PATH_SUBTYPE_1394 0x04
#define EFI_DEVICE_PATH_SUBTYPE_USB 0x05
#define EFI_DEVICE_PATH_SUBTYPE_SATA 0x12
#define EFI_DEVICE_PATH_SUBTYPE_USB_WWID 0x13
#define EFI_DEVICE_PATH_SUBTYPE_DEVICE_LOGICAL_UNIT 0x14
#define EFI_DEVICE_PATH_SUBTYPE_USB_CLASS 0x0f
#define EFI_DEVICE_PATH_SUBTYPE_I2O 0x06
#define EFI_DEVICE_PATH_SUBTYPE_MAC_ADDRESS 0x0b
#define EFI_DEVICE_PATH_SUBTYPE_IPv4 0x0c
#define EFI_DEVICE_PATH_SUBTYPE_IPv6 0x0d
#define EFI_DEVICE_PATH_SUBTYPE_VLAN 0x14
#define EFI_DEVICE_PATH_SUBTYPE_INFINIBAND 0x09
#define EFI_DEVICE_PATH_SUBTYPE_UART 0x0e
#define EFI_DEVICE_PATH_SUBTYPE_VENDOR_DEFINED_MESSAGING 0x0a
#define EFI_DEVICE_PATH_SUBTYPE_UART_FLOW_CONTROL 0x10
#define EFI_DEVICE_PATH_SUBTYPE_SAS 0x0a
#define EFI_DEVICE_PATH_SUBTYPE_SAS_EX 0x16
#define EFI_DEVICE_PATH_SUBTYPE_ISCSI 0x13
#define EFI_DEVICE_PATH_SUBTYPE_NVM_EXPRESS_NAMESPACE 0x17
#define EFI_DEVICE_PATH_SUBTYPE_URI 0x18
#define EFI_DEVICE_PATH_SUBTYPE_UFS 0x19
#define EFI_DEVICE_PATH_SUBTYPE_SD 0x1a
#define EFI_DEVICE_PATH_SUBTYPE_BLUETOOTH 0x1b
#define EFI_DEVICE_PATH_SUBTYPE_WIRELESS 0x1c
#define EFI_DEVICE_PATH_SUBTYPE_EMMC 0x1d
#define EFI_DEVICE_PATH_SUBTYPE_BLUETOOTH_LE 0x1e
#define EFI_DEVICE_PATH_SUBTYPE_DNS 0x1f
#define EFI_DEVICE_PATH_SUBTYPE_NVDIMM_NAMESPACE 0x20
#define EFI_DEVICE_PATH_SUBTYPE_REST_SERVICE 0x21
#define EFI_DEVICE_PATH_SUBTYPE_VENDOR_SPECIFIC_REST_SERVICE 0x21
#define EFI_DEVICE_PATH_SUBTYPE_NVMEOF_NAMESPACE 0x22

#define EFI_DEVICE_PATH_SUBTYPE_HARD_DRIVE 0x01
#define EFI_DEVICE_PATH_SUBTYPE_CDROM 0x02
#define EFI_DEVICE_PATH_SUBTYPE_VENDOR_DEFINED 0x03
#define EFI_DEVICE_PATH_SUBTYPE_FILE_PATH 0x04
#define EFI_DEVICE_PATH_SUBTYPE_MEDIA_PROTOCOL 0x05
#define EFI_DEVICE_PATH_SUBTYPE_PIWG_FW_FILE 0x06
#define EFI_DEVICE_PATH_SUBTYPE_PIWG_FW_VOLUME 0x07
#define EFI_DEVICE_PATH_SUBTYPE_RELATIVE_OFFSET_RANGE 0x08
#define EFI_DEVICE_PATH_SUBTYPE_RAM_DISK 0x09

#define EFI_DEVICE_PATH_SUBTYPE_BIOS_BOOT_SPECIFICATION 0x01

#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_RESERVED 0x00
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_FLOPPY 0x01
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_HARD_DISK 0x02
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_CD_ROM 0x03
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_PCMCIA 0x04
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_USB 0x05
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_EMBEDDED_NETWORK 0x06
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_BEV_DEVICE 0x80
#define EFI_BIOS_BOOT_SPECIFICATION_DEVICE_TYPE_UNKNOWN 0xff

typedef struct EFI_DEVICE_PATH_PROTOCOL {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
} EFI_DEVICE_PATH_PROTOCOL;

typedef struct EFI_PCI_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 Function;
    UINT8 Device;
} EFI_PCI_DEVICE_PATH;

typedef struct EFI_PCCARD_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 FunctionNumber;
} EFI_PCCARD_DEVICE_PATH;

typedef struct EFI_MEMORY_MAPPED_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 MemoryType;
    UINT64 StartAddress;
    UINT64 EndAddress;
} EFI_MEMORY_MAPPED_DEVICE_PATH;

typedef struct EFI_VENDOR_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_GUID VendorGUID;
    UINT8 VendorDefinedData[];
} EFI_VENDOR_DEVICE_PATH;

typedef struct EFI_CONTROLLER_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 ControllerNumber;
} EFI_CONTROLLER_DEVICE_PATH;

typedef struct EFI_BMC_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 InterfaceType;
    UINT64 BaseAddress;
} EFI_BMC_DEVICE_PATH;

typedef struct EFI_ACPI_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 HID;
    UINT32 UID;
} EFI_ACPI_DEVICE_PATH;

typedef struct EFI_EXPANDED_ACPI_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 HID;
    UINT32 UID;
    UINT32 CID;
    UINT8 STR[];
} EFI_EXPANDED_ACPI_DEVICE_PATH;

typedef struct EFI_ADR_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 _ADR[];
} EFI_ADR_DEVICE_PATH;

typedef struct EFI_NVDIMM_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 NFITDeviceHandle;
} EFI_NVDIMM_DEVICE_PATH;

typedef struct EFI_ATAPI_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 PrimarySecondary;
    UINT8 SlaveMaster;
    UINT16 LUN;
} EFI_ATAPI_DEVICE_PATH;

typedef struct EFI_SCSI_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT16 TargetId;
    UINT16 LUN;
} EFI_SCSI_DEVICE_PATH;

typedef struct EFI_FIBRECHANNEL_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 Reserved;
    UINT64 WorldWideName;
    UINT64 LUN;
} EFI_FIBRECHANNEL_DEVICE_PATH;

typedef struct EFI_FIBRECHANNEL_EX_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 Reserved;
    UINT64 WorldWideName;
    UINT64 LUN;
} EFI_FIBRECHANNEL_EX_DEVICE_PATH;

typedef struct EFI_1394_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 Reserved;
    UINT64 Guid;
} EFI_1394_DEVICE_PATH;

typedef struct EFI_USB_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 USBParentPortNumber;
    UINT8 Interface;
} EFI_USB_DEVICE_PATH;

typedef struct EFI_SATA_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT16 HBAPortNumber;
    UINT16 PortMultiplierPortNumber;
    UINT16 LUN;
} EFI_SATA_DEVICE_PATH;

typedef struct EFI_USB_WWID_DEVICE_PATH {    
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT16 InterfaceNumber;
    UINT16 VendorId;
    UINT16 DeviceProductId;
    UINT8 SerialNumber[];
} EFI_USB_WWID_DEVICE_PATH;

typedef struct EFI_DEVICE_LOGICAL_UNIT {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 LUN;
} EFI_DEVICE_LOGICAL_UNIT;

typedef struct EFI_USB_CLASS_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT16 VendorId;
    UINT16 ProductId;
    UINT8 DeviceClass;
    UINT8 DeviceSubClass;
    UINT8 DeviceProtocol;
} EFI_USB_CLASS_DEVICE_PATH;

typedef struct EFI_I2O_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 TID;
} EFI_I2O_DEVICE_PATH;

typedef struct EFI_MAC_ADDRESS_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_MAC_ADDRESS MACAddress;
    UINT8 IfType;
} EFI_MAC_ADDRESS_DEVICE_PATH;

typedef struct EFI_IPV4_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_IPv4_ADDRESS LocalIpAddress;
    EFI_IPv4_ADDRESS RemoteIpAddress;
    UINT16 LocalPort;
    UINT16 RemotePort;
    UINT16 Protocol;
    BOOLEAN StaticIpAddress;
    EFI_IPv4_ADDRESS GatewayIpAddress;
    EFI_IPv4_ADDRESS SubnetMask;
} EFI_IPV4_DEVICE_PATH;

typedef struct EFI_IPV6_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_IPv6_ADDRESS LocalIpAddress;
    EFI_IPv6_ADDRESS RemoteIpAddress;
    UINT16 LocalPort;
    UINT16 RemotePort;
    UINT16 Protocol;
    BOOLEAN IPAddressOrigin;
    UINT8 PrefixLength;
    EFI_IPv6_ADDRESS GatewayIPAddress;
} EFI_IPV6_DEVICE_PATH;

typedef struct EFI_VLAN_DEVICE_PATH_NODE {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT16 Vlanid;
} EFI_VLAN_DEVICE_PATH_NODE;

typedef struct EFI_INFINIBAND_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 ResourceFlags;
    UINT8 PortGID[16];
    UINT64 ServiceId;
    UINT64 TargetPortId;
    UINT64 DeviceId;
} EFI_INFINIBAND_DEVICE_PATH;

typedef struct EFI_UART_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 Reserved;
    UINT64 BaudRate;
    UINT8 DataBits;
    UINT8 Parity;
    UINT8 StopBits;
} EFI_UART_DEVICE_PATH;

typedef struct EFI_VENDOR_DEFINED_MESSAGING_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_GUID VendorGUID;
    UINT8 VendorDefinedData[];
} EFI_VENDOR_DEFINED_MESSAGING_DEVICE_PATH;

typedef struct EFI_UART_FLOW_CONTROL_MESSAGING_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_GUID VendorGUID;
    UINT32 FlowControlMap;
} EFI_UART_FLOW_CONTROL_MESSAGING_PATH;

typedef struct EFI_SAS_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_GUID VendorGUID;
    UINT32 Reserved;
    UINT64 SasAddress;
    UINT64 LUN;
    UINT16 DeviceTopologyInfo;
    UINT16 RelativeTargetPort;
} EFI_SAS_DEVICE_PATH;

typedef struct EFI_SAS_EXTENDED_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT64 SasAddress;
    UINT64 LUN;
    UINT16 DeviceTopologyInfo;
    UINT16 RelativeTargetPort;
} EFI_SAS_EXTENDED_DEVICE_PATH;

typedef struct EFI_ISCSI_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT16 Protocol;
    UINT16 Options;
    UINT64 LUN;
    UINT16 TargetPortalGroupTag;
    UINT8 iSCSITargetName[];
} EFI_ISCSI_DEVICE_PATH;

typedef struct EFI_NVM_EXPRESS_NAMESPACE_MESSAGING_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 NamespaceId;
    UINT64 IEEEExtendedUniqueIdentifier;
} EFI_NVM_EXPRESS_NAMESPACE_DEVICE_MESSAGING_PATH;

typedef struct EFI_URI_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    CHAR8 Uri[];
} EFI_URI_DEVICE_PATH;

typedef struct EFI_UFS_DEVICE_MESSAGING_DEVICE_PATH_NODE {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 TargetID;
    UINT8 LUN;
} EFI_UFS_DEVICE_MESSAGING_DEVICE_PATH_NODE;

typedef struct EFI_SD_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 SlotNumber;
} EFI_SD_DEVICE_PATH;

typedef struct EFI_BLUETOOTH_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 DeviceAddress[6];
} EFI_BLUETOOTH_DEVICE_PATH;

typedef struct EFI_WIRELESS_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 SSID[32];
} EFI_WIRELESS_DEVICE_PATH;

typedef struct EFI_EMMC_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 SlotNumber;
} EFI_EMMC_DEVICE_PATH;

typedef struct EFI_BLUETOOTH_LE_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 DeviceAddress[6];
    UINT8 AddressType;
} EFI_BLUETOOTH_LE_DEVICE_PATH;

typedef struct EFI_DNS_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    BOOLEAN IsIPv6;
    EFI_IP_ADDRESS DNSServerAddress[];
} EFI_DNS_DEVICE_PATH;

typedef struct EFI_NVDIMM_NAMESPACE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_GUID Uuid;
} EFI_NVDIMM_NAMESPACE_PATH;

typedef struct EFI_REST_SERVICE_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 RESTService;
    UINT8 AccessMode;
} EFI_REST_SERVICE_DEVICE_PATH;

typedef struct EFI_VENDOR_SPECIFIC_REST_SERVICE_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 RESTService;
    UINT8 AccessMode;
    EFI_GUID VendorGUID;
    UINT8 VendorDefinedData[];
} EFI_VENDOR_SPECIFIC_REST_SERVICE_DEVICE_PATH;

typedef struct EFI_NVMEOF_NAMESPACE_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 NIDT;
    UINT8 NID[16];
    UINT8 SubsystemNQN[];
} EFI_NVMEOF_NAMESPACE_DEVICE_PATH;

typedef struct EFI_HARD_DRIVE_MEDIA_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 PartitionNumber;
    UINT64 PartitionStart;
    UINT64 PartitionSize;
    UINT8 Signature[16];
    UINT8 PartitionFormat;
    UINT8 SignatureType;
} EFI_HARD_DRIVE_MEDIA_DEVICE_PATH;

typedef struct EFI_CDROM_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 BootEntry;
    UINT64 PartitionStart;
    UINT64 PartitionSize;
} EFI_CDROM_DEVICE_PATH;

typedef struct EFI_VENDOR_DEFINED_MEDIA_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_GUID VendorGUID;
    UINT8 VendorDefinedData[];
} EFI_VENDOR_DEFINED_MEDIA_DEVICE_PATH;

typedef struct EFI_FILE_PATH_MEDIA_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    CHAR8 PathName[];
} EFI_FILE_PATH_MEDIA_DEVICE_PATH;

typedef struct EFI_MEDIA_PROTOCOL_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    EFI_GUID ProtocolGUID;
} EFI_MEDIA_PROTOCOL_DEVICE_PATH;

typedef struct EFI_PIWG_FW_FILE_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 Contents[];
} EFI_PIWG_FW_FILE_DEVICE_PATH;

typedef struct EFI_PIWG_FW_VOLUME_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT8 Contents[];
} EFI_PIWG_FW_VOLUME_DEVICE_PATH;

typedef struct EFI_RELATIVE_OFFSET_RANGE_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT32 Reserved;
    UINT64 StartingOffset;
    UINT64 EndingOffset;
} EFI_RELATIVE_OFFSET_RANGE_DEVICE_PATH;

typedef struct EFI_RAM_DISK_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT64 StartingAddress;
    UINT64 EndingAddress;
    EFI_GUID DiskTypeGUID;
    UINT16 DiskInstance;
} EFI_RAM_DISK_DEVICE_PATH;

typedef struct EFI_BIOSBOOT_SPECIFICATION_DEVICE_PATH {
    UINT8 Type;
    UINT8 SubType;
    UINT16 Length;
    UINT16 DeviceType;
    UINT16 StatusFlag;
    UINT8 DescriptionString[];
} EFI_BIOSBOOT_SPECIFICATION_DEVICE_PATH;

#endif // _EFI_DPP_H
