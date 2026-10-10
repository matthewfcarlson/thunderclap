// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 12/12)
// FUN_00278de0 @ 0x00278de0
typedef unsigned long DWORD;
extern int DAT_0052c27c;
extern int DAT_0052c274;
extern unsigned int DAT_0052c278;
extern char *DAT_0052c270;
extern "C" int __stdcall FUN_002109b6(int, int);
extern "C" int __cdecl FUN_002781c0(int, void *);
extern "C" int __stdcall FUN_002101d4(int, unsigned int, int, int);
extern "C" int __stdcall FUN_0021007a(int, int, int, void *, int);
namespace XAPILIB { extern "C" int __stdcall GetLastError(); }
struct DataBlock { DWORD words[5]; };
struct Scratch { DWORD unused; DataBlock block; };
struct Target {
 char pad[0xb4];
 int error;
 int FUN_002787c0(int);
 bool FUN_00278de0();
};
bool Target::FUN_00278de0() {
 if (DAT_0052c27c != 2) return true;
 int length = FUN_002109b6(DAT_0052c274, 0);
 if (length == -1) {
  error = FUN_002787c0(XAPILIB::GetLastError());
  return false;
 }
 Scratch scratch;
 if (!FUN_002781c0(length, &scratch.block)) {
  error = FUN_002787c0(XAPILIB::GetLastError());
  return false;
 }
 unsigned int offset = DAT_0052c278 << 13;
 unsigned int end = offset + 8192;
 if (end > (unsigned int)length) end = length;
 DataBlock *trailer = (DataBlock *)(DAT_0052c270 + end - offset - 20);
 *trailer = scratch.block;
 if (FUN_002101d4(DAT_0052c274, offset, 0, 0) == (int)offset &&
     FUN_0021007a(DAT_0052c274, (int)DAT_0052c270, end - offset, &scratch, 0)) {
  DAT_0052c27c = 1;
  return true;
 }
 error = FUN_002787c0(XAPILIB::GetLastError());
 return false;
}
