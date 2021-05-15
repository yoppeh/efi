/*
 * efi-pbcp.h
 *
 * Pxe Base Code Protocol and Pxe Base Code Callback Protocol.
 */

#ifndef __EFI_PBCP_H
#define __EFI_PBCP_H

#include <efi.h>


// first definitions for PXE_BASE_CODE_PROTOCOL constants
#define EFI_PXE_BASE_CODE_PROTOCOL_GUID {0x03C4E603, 0xAC28, 0x11d3, {0x9A, 0x2D, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D}}

#define EFI_PXE_BASE_CODE_MAX_IPCNT         8
#define EFI_PXE_BASE_CODE_MAX_ARP_ENTRIES   8
#define EFI_PXE_BASE_CODE_MAX_ROUTE_ENTRIES 8

#define EFI_PXE_BASE_CODE_BOOT_LAYER_INITIAL 0


// now definitions for PXE_BASE_CODE_CALLBACK_PROTOCOL constants
#define EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL_GUID {0x245DCA21, 0xFB7B, 0x11d3, {0x8F, 0x01, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B}}

#define EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL_REVISION 0x00010000


// types for the PXE_BASE_CODE_PROTOCOL
struct EFI_PXE_BASE_CODE_PROTOCOL;

typedef struct {
    UINT8 Addr[32];
} EFI_MAC_ADDRESS;

typedef struct {
    UINT8 Addr[4];
} EFI_IPv4_ADDRESS;

typedef struct {
    UINT8 Addr[16];
} EFI_IPv6_ADDRESS;

typedef union {
    UINT32 Addr[4];
    EFI_IPv4_ADDRESS v4;
    EFI_IPv6_ADDRESS v6;
} EFI_IP_ADDRESS;

typedef UINT16 EFI_PXE_BASE_CODE_UDP_PORT;

typedef struct {
    UINT16          Type;
    BOOLEAN         AcceptAnyResponse;
    UINT8           _reserved;
    EFI_IP_ADDRESS  IpAddr;
} EFI_PXE_BASE_CODE_SRVLIST;

typedef struct {
    BOOLEAN        UseMCast;
    BOOLEAN        UseBCast;
    BOOLEAN        UseUCast;
    BOOLEAN        MustUseList;
    EFI_IP_ADDRESS ServerMCastIp;
    UINT16         IpCnt;
    EFI_PXE_BASE_CODE_SRVLIST SrvList[EFI_PXE_BASE_CODE_MAX_IPCNT];
} EFI_PXE_BASE_CODE_DISCOVER_INFO;

typedef struct {
    EFI_IP_ADDRESS             MCastIp;
    EFI_PXE_BASE_CODE_UDP_PORT CPort;
    EFI_PXE_BASE_CODE_UDP_PORT SPort;
    UINT16                     ListenTimeout;
    UINT16                     TransmitTimeout;
} EFI_PXE_BASE_CODE_MTFTP_INFO;

typedef struct {
    UINT8 Filters;
    UINT8 IpCnt;
    UINT16 _reserved;
    EFI_IP_ADDRESS IpList[EFI_PXE_BASE_CODE_MAX_IPCNT];
} EFI_PXE_BASE_CODE_IP_FILTER;

typedef struct {
    EFI_IP_ADDRESS  IpAddr;
    EFI_MAC_ADDRESS MacAddr;
} EFI_PXE_BASE_CODE_ARP_ENTRY;

typedef struct {
    EFI_IP_ADDRESS  IpAddr;
    EFI_IP_ADDRESS  SubnetMask;
    EFI_IP_ADDRESS  GwAddr;
} EFI_PXE_BASE_CODE_ROUTE_ENTRY;

typedef struct {
    UINT8  BootpOpcode;
    UINT8  BootpHwType;
    UINT8  BootpHwAddrLen;
    UINT8  BootpGateHops;
    UINT32 BootpIdent;
    UINT16 BootpSeconds;
    UINT16 BootpFlags;
    UINT8  BootpCiAddr[4];
    UINT8  BootpYiAddr[4];
    UINT8  BootpSiAddr[4];
    UINT8  BootpGiAddr[4];
    UINT8  BootpHwAddr[16];
    UINT8  BootpSrvName[64];
    UINT8  BootpBootFile[128];
    UINT32 DhcpMagik;
    UINT8  DhcpOptions[56];
} EFI_PXE_BASE_CODE_DHCPV4_PACKET;

typedef struct {
    UINT32 MessageType: 8;
    UINT32 TransactionId: 24;
    UINT8  DhcpOptions[1024];
} EFI_PXE_BASE_CODE_DHCPV6_PACKET;

typedef union {
    UINT8                           Raw[1472];
    EFI_PXE_BASE_CODE_DHCPV6_PACKET Dhcpv6;
    EFI_PXE_BASE_CODE_DHCPV4_PACKET Dhcpv4;
} EFI_PXE_BASE_CODE_PACKET;

typedef struct {
    UINT8 Type;
    UINT8 Code;
    UINT16 Checksum;
    union {
        UINT32 _reserved;
        UINT32 Mtu;
        UINT32 Pointer;
        struct {
            UINT16 Identifier;
            UINT16 Sequence;
        } Echo;
    } u;
    UINT8 Data[494];
} EFI_PXE_BASE_CODE_ICMP_ERROR;

typedef struct {
    UINT8 ErrorCode;
    CHAR8 ErrorString[127];
} EFI_PXE_BASE_CODE_TFTP_ERROR;

typedef struct {
    BOOLEAN                       Started;
    BOOLEAN                       IPv6Available;
    BOOLEAN                       IPv6Supported;
    BOOLEAN                       UsingIPv6;
    BOOLEAN                       BisSupported;
    BOOLEAN                       BisDetected;
    BOOLEAN                       AutoArp;
    BOOLEAN                       SendGUID;
    BOOLEAN                       DhcpDiscoverValid;
    BOOLEAN                       DhcpAckReceived;
    BOOLEAN                       ProxyOfferReceived;
    BOOLEAN                       PxeDiscoverValid;
    BOOLEAN                       PxeReplyReceived;
    BOOLEAN                       PxeBisReplyReceived;
    BOOLEAN                       IcmpErrorReceived;
    BOOLEAN                       TftpErrorReceived;
    BOOLEAN                       MakeCallbacks;
    UINT8                         TTL;
    UINT8                         ToS;
    EFI_IP_ADDRESS                StationIp;
    EFI_IP_ADDRESS                SubnetMask;
    EFI_PXE_BASE_CODE_PACKET      DhcpDiscover;
    EFI_PXE_BASE_CODE_PACKET      DhcpAck;
    EFI_PXE_BASE_CODE_PACKET      ProxyOffer;
    EFI_PXE_BASE_CODE_PACKET      PxeDiscover;
    EFI_PXE_BASE_CODE_PACKET      PxeReply;
    EFI_PXE_BASE_CODE_PACKET      PxeBisReply;
    EFI_PXE_BASE_CODE_IP_FILTER   IpFilter;
    UINT32                        ArpCacheEntries;
    EFI_PXE_BASE_CODE_ARP_ENTRY   ArpCache[EFI_PXE_BASE_CODE_MAX_ARP_ENTRIES];
    UINT32                        RouteTableEntries;
    EFI_PXE_BASE_CODE_ROUTE_ENTRY RouteTable[EFI_PXE_BASE_CODE_MAX_ROUTE_ENTRIES];
    EFI_PXE_BASE_CODE_ICMP_ERROR  IcmpError;
    EFI_PXE_BASE_CODE_TFTP_ERROR  TftpError;
} EFI_PXE_BASE_CODE_MODE;

typedef enum {
    EFI_PXE_BASE_CODE_TFTP_FIRST,
    EFI_PXE_BASE_CODE_TFTP_GET_FILE_SIZE,
    EFI_PXE_BASE_CODE_TFTP_READ_FILE,
    EFI_PXE_BASE_CODE_TFTP_WRITE_FILE,
    EFI_PXE_BASE_CODE_TFTP_READ_DIRECTORY,
    EFI_PXE_BASE_CODE_MTFTP_GET_FILE_SIZE,
    EFI_PXE_BASE_CODE_MTFTP_READ_FILE,
    EFI_PXE_BASE_CODE_MTFTP_READ_DIRECTORY,
    EFI_PXE_BASE_CODE_MTFTP_LAST
} EFI_PXE_BASE_CODE_TFTP_OPCODE;

typedef EFI_STATUS (*EFI_PXE_BASE_CODE_START) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, BOOLEAN UseIpv6);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_STOP) (struct EFI_PXE_BASE_CODE_PROTOCOL *This);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_DHCP) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, BOOLEAN SortOffers);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_DISCOVER) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, UINT16 Type, UINT16* Layer, BOOLEAN UseBis, EFI_PXE_BASE_CODE_DISCOVER_INFO* Info);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_MTFTP) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, EFI_PXE_BASE_CODE_TFTP_OPCODE Operation, VOID* Buffer, BOOLEAN Overwrite, UINT64* BufferSize, UINTN* BlockSize, EFI_IP_ADDRESS* ServerIp, CHAR8* Filename, EFI_PXE_BASE_CODE_MTFTP_INFO* Info, BOOLEAN DontUseBuffer);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_UDP_WRITE) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, UINT16 OpFlags, EFI_IP_ADDRESS* DestIp, EFI_PXE_BASE_CODE_UDP_PORT* DestPort, EFI_IP_ADDRESS* GatewayIp, EFI_IP_ADDRESS* SrcIp, EFI_PXE_BASE_CODE_UDP_PORT* SrcPort, UINTN* HeaderSize, VOID* HeaderPtr, UINTN* BufferSize, VOID* BufferPtr);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_UDP_READ) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, UINT16 OpFlags, EFI_IP_ADDRESS* DestIp, EFI_PXE_BASE_CODE_UDP_PORT* DestPort, EFI_IP_ADDRESS* SrcIp, EFI_PXE_BASE_CODE_UDP_PORT* SrcPort, UINTN* HeaderSize, VOID* HeaderPtr, UINTN* BufferSize, VOID* BufferPtr);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_SET_IP_FILTER) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, EFI_PXE_BASE_CODE_IP_FILTER* NewFilter);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_ARP) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, EFI_IP_ADDRESS* IpAddr, EFI_MAC_ADDRESS* MacAddr);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_SET_PARAMETERS) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, BOOLEAN* NewAutoArp, BOOLEAN* NewSendGUID, UINT8* NewTTL, UINT8* NewToS, BOOLEAN* NewMakeCallback);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_SET_STATION_IP) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, EFI_IP_ADDRESS* NewStationIp, EFI_IP_ADDRESS* NewSubnetMask);
typedef EFI_STATUS (*EFI_PXE_BASE_CODE_SET_PACKETS) (struct EFI_PXE_BASE_CODE_PROTOCOL *This, BOOLEAN* NewDhcpDiscoverValid, BOOLEAN* NewDhcpAckReceived, BOOLEAN* NewProxyOfferReceived, BOOLEAN* NewPxeOfferValid, BOOLEAN* NewPxeReplyReceived, BOOLEAN* NewPxeBisReplyReceived, EFI_PXE_BASE_CODE_PACKET* NewDhcpDiscover, EFI_PXE_BASE_CODE_PACKET* NewDhcpAck, EFI_PXE_BASE_CODE_PACKET* NewProxyOffer, EFI_PXE_BASE_CODE_PACKET* NewPxeOffer, EFI_PXE_BASE_CODE_PACKET* NewPxeReply, EFI_PXE_BASE_CODE_PACKET* NewPxeBisReply);

typedef struct EFI_PXE_BASE_CODE_PROTOCOL {
    UINT64 Revision;
    EFI_PXE_BASE_CODE_START Start;
    EFI_PXE_BASE_CODE_STOP Stop;
    EFI_PXE_BASE_CODE_DHCP Dhcp;
    EFI_PXE_BASE_CODE_DISCOVER Discover;
    EFI_PXE_BASE_CODE_MTFTP Mtftp;
    EFI_PXE_BASE_CODE_UDP_WRITE UdpWrite;
    EFI_PXE_BASE_CODE_UDP_READ UdpRead;
    EFI_PXE_BASE_CODE_SET_IP_FILTER SetIpFilter;
    EFI_PXE_BASE_CODE_ARP Arp;
    EFI_PXE_BASE_CODE_SET_PARAMETERS SetParameters;
    EFI_PXE_BASE_CODE_SET_STATION_IP SetStationIp;
    EFI_PXE_BASE_CODE_SET_PACKETS SetPackets;
    EFI_PXE_BASE_CODE_MODE *Mode;
} EFI_PXE_BASE_CODE_PROTOCOL;

typedef enum {
    EFI_PXE_BASE_CODE_CALLBACK_STATUS_FIRST,
    EFI_PXE_BASE_CODE_CALLBACK_STATUS_CONTINUE,
    EFI_PXE_BASE_CODE_CALLBACK_STATUS_ABORT,
    EFI_PXE_BASE_CODE_CALLBACK_STATUS_LAST
} EFI_PXE_BASE_CODE_CALLBACK_STATUS;

typedef enum {
    EFI_PXE_BASE_CODE_FUNCTION_FIRST,
    EFI_PXE_BASE_CODE_FUNCTION_DHCP,
    EFI_PXE_BASE_CODE_FUNCTION_DISCOVER,
    EFI_PXE_BASE_CODE_FUNCTION_MTFTP,
    EFI_PXE_BASE_CODE_FUNCTION_UDP_WRITE,
    EFI_PXE_BASE_CODE_FUNCTION_UDP_READ,
    EFI_PXE_BASE_CODE_FUNCTION_ARP,
    EFI_PXE_BASE_CODE_FUNCTION_IGMP,
    EFI_PXE_BASE_CODE_PXE_FUNCTION_LAST
} EFI_PXE_BASE_CODE_FUNCTION;


// types for the PXE_BASE_CODE_CALLBACK_PROTOCOL

struct EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL;

typedef EFI_PXE_BASE_CODE_CALLBACK_STATUS (*EFI_PXE_CALLBACK) (struct EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL* This, EFI_PXE_BASE_CODE_FUNCTION Function, BOOLEAN Received, UINT32 PacketLen, EFI_PXE_BASE_CODE_PACKET* Packet);

typedef struct EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL {
    UINT64 Revision;
    EFI_PXE_CALLBACK Callback;
} EFI_PXE_BASE_CODE_CALLBACK_PROTOCOL;

#endif /* __EFI_PBCP_H */
