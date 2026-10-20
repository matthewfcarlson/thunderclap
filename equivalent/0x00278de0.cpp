// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 12/12)
// FUN_00278de0 @ 0x00278de0
#include "compat/ptr.h"
#include "decls/data/platform/xbox/core.h"

typedef unsigned long DWORD;
extern "C" int __stdcall FUN_002109b6(int, int);
extern "C" char __cdecl FUN_002781c0(int, void *);
extern "C" int __stdcall FUN_002101d4(int, unsigned int, int, int);
extern "C" int __stdcall FUN_0021007a(int, int, int, void *, int);
namespace XAPILIB { extern "C" int __stdcall GetLastError(); }
struct DataBlock_278de0 { DWORD words[5]; };
struct Scratch_278de0 { DWORD unused; DataBlock_278de0 block; };
struct Target_278de0 {
 char pad[0xb4];
 int error;
 int FUN_002787c0(int);
 bool FUN_00278de0();
};
bool Target_278de0::FUN_00278de0() {
 if ((*(int*)((char*)&DAT_0052c270 + 12)) != 2) return true;
 int length = FUN_002109b6((*(int*)((char*)&DAT_0052c270 + 4)), 0);
 if (length == -1) {
  error = FUN_002787c0(XAPILIB::GetLastError());
  return false;
 }
 Scratch_278de0 scratch;
 if (!FUN_002781c0(length, &scratch.block)) {
  error = FUN_002787c0(XAPILIB::GetLastError());
  return false;
 }
 unsigned int offset = (*(unsigned int*)((char*)&DAT_0052c270 + 8)) << 13;
 unsigned int end = offset + 8192;
 if (end > (unsigned int)length) end = length;
 DataBlock_278de0 *trailer = (DataBlock_278de0 *)((*(char**)&DAT_0052c270) + end - offset - 20);
 *trailer = scratch.block;
 if (FUN_002101d4((*(int*)((char*)&DAT_0052c270 + 4)), offset, 0, 0) == (int)offset &&
     FUN_0021007a((*(int*)((char*)&DAT_0052c270 + 4)), (hulk_intptr)(*(char**)&DAT_0052c270), end - offset, &scratch, 0)) {
  (*(int*)((char*)&DAT_0052c270 + 12)) = 1;
  return true;
 }
 error = FUN_002787c0(XAPILIB::GetLastError());
 return false;
}
