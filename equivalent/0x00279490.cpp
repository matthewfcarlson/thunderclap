// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 19/20, incomplete)
// FUN_00279490 @ 0x00279490
#include "decls/data/platform/xbox/core.h"

typedef unsigned int uint_279490;
struct Header_279490 { uint_279490 word[5]; };
struct XboxSaveDrive_279490 {
 char pad[0xb4];
 uint_279490 error;
 unsigned char FUN_00278de0();
 uint_279490 FUN_002787c0(uint_279490);
 void FUN_002789e0(uint_279490);
 bool FUN_00279490(uint_279490, uint_279490);
};
struct Cache_279490 { char *buffer; uint_279490 file; uint_279490 block; uint_279490 valid; };
extern "C" uint_279490 __stdcall FUN_002109b6(uint_279490, uint_279490);
extern "C" uint_279490 __stdcall FUN_002101d4(uint_279490, uint_279490, uint_279490, uint_279490);
extern "C" uint_279490 __stdcall FUN_0020ff8d(uint_279490, char *, uint_279490, uint_279490 *, uint_279490);
extern "C" unsigned char __cdecl FUN_002781c0(uint_279490, Header_279490 *);
namespace XAPILIB { extern "C" uint_279490 __stdcall GetLastError(); }
bool XboxSaveDrive_279490::FUN_00279490(uint_279490 file, uint_279490 block) {
 if ((*(Cache_279490*)&DAT_0052c270).valid && (*(Cache_279490*)&DAT_0052c270).file == file && (*(Cache_279490*)&DAT_0052c270).block == block) return true;
 uint_279490 length = FUN_002109b6(file, 0);
 if (length == 0xffffffff) { error = FUN_002787c0(XAPILIB::GetLastError()); return false; }
 if (!FUN_00278de0()) return false;
 uint_279490 offset = block << 13;
 uint_279490 end = offset + 0x2000;
 if (end >= length) end = length;
 uint_279490 amount = end - offset;
 uint_279490 footer = end - 20;
 (*(Cache_279490*)&DAT_0052c270).valid = 0;
 uint_279490 bytesRead;
 if (FUN_002101d4(file, offset, 0, 0) != offset ||
     !FUN_0020ff8d(file, (*(Cache_279490*)&DAT_0052c270).buffer, amount, &bytesRead, 0)) {
  error = FUN_002787c0(XAPILIB::GetLastError()); return false;
 }
 uint_279490 address = (uint_279490)(*(Cache_279490*)&DAT_0052c270).buffer;
 Header_279490 expected = *(Header_279490 *)(address + footer - offset);
 Header_279490 actual;
 (*(Cache_279490*)&DAT_0052c270).file = file;
 (*(Cache_279490*)&DAT_0052c270).block = block;
 if (!FUN_002781c0(length, &actual)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
 for (int i = 0; i < 5; ++i) if (actual.word[i] != expected.word[i]) { error = 12; return false; }
 (*(Cache_279490*)&DAT_0052c270).valid = 1;
 return true;
}