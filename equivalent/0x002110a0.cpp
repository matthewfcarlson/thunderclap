// STATUS: equivalent (tools/equiv.py level 3: 3046 inputs, branch coverage 14/14)
// FUN_002110a0 @ 0x002110a0
typedef unsigned long DWORD;
struct Header { char pad0[24]; DWORD length; char pad1[7]; unsigned char flags; char payload[72]; DWORD offset; DWORD size; };
struct Block { unsigned short size; unsigned short version; char data[108]; };
struct Result { char pad[16]; Block* block; unsigned char digest[20]; };
struct Overlapped { DWORD internal; DWORD internalHigh; DWORD offset; DWORD offsetHigh; DWORD event; };
struct SHAContext { unsigned char bytes[116]; };
extern int __stdcall FUN_0020ff8d(void*, Block*, DWORD, DWORD*, Overlapped*);
namespace xboxkrnl { void __stdcall XcSHAInit(SHAContext*); void __stdcall XcSHAUpdate(SHAContext*, const void*, DWORD); }
void __stdcall FUN_00212a10(SHAContext*, void*);
namespace XAPILIB { void __stdcall SetLastError(DWORD); }
int __stdcall FUN_002110a0(void* file, Header* header, Result* result) {
 Block* block = result->block;
 if (!(header->flags & 128)) return 1;
 if (header->offset && header->size == 112) {
  Overlapped overlapped = {0,0,0,0,0};
  overlapped.offset = header->offset;
  DWORD read;
  if (FUN_0020ff8d(file, block, 112, &read, &overlapped) && read == 112 && block->size == 112 && block->version == 1) {
   SHAContext sha;
   xboxkrnl::XcSHAInit(&sha);
   xboxkrnl::XcSHAUpdate(&sha, header->payload, header->length - 36);
   xboxkrnl::XcSHAUpdate(&sha, block, 12);
   FUN_00212a10(&sha, result->digest);
   return 1;
  }
 }
 result->block = 0;
 XAPILIB::SetLastError(13);
 return 0;
}