// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 19/20, incomplete)
// FUN_00279490 @ 0x00279490
typedef unsigned int uint;
struct Header { uint word[5]; };
struct Object {
 char pad[0xb4];
 uint error;
 unsigned char FUN_00278de0();
 uint FUN_002787c0(uint);
 void FUN_002789e0(uint);
 bool FUN_00279490(uint, uint);
};
struct Cache { char *buffer; uint file; uint block; uint valid; };
extern Cache DAT_0052c270;
extern "C" uint __stdcall FUN_002109b6(uint, uint);
extern "C" uint __stdcall FUN_002101d4(uint, uint, uint, uint);
extern "C" uint __stdcall FUN_0020ff8d(uint, char *, uint, uint *, uint);
extern "C" unsigned char __cdecl FUN_002781c0(uint, Header *);
namespace XAPILIB { extern "C" uint __stdcall GetLastError(); }
bool Object::FUN_00279490(uint file, uint block) {
 if (DAT_0052c270.valid && DAT_0052c270.file == file && DAT_0052c270.block == block) return true;
 uint length = FUN_002109b6(file, 0);
 if (length == 0xffffffff) { error = FUN_002787c0(XAPILIB::GetLastError()); return false; }
 if (!FUN_00278de0()) return false;
 uint offset = block << 13;
 uint end = offset + 0x2000;
 if (end >= length) end = length;
 uint amount = end - offset;
 uint footer = end - 20;
 DAT_0052c270.valid = 0;
 uint bytesRead;
 if (FUN_002101d4(file, offset, 0, 0) != offset ||
     !FUN_0020ff8d(file, DAT_0052c270.buffer, amount, &bytesRead, 0)) {
  error = FUN_002787c0(XAPILIB::GetLastError()); return false;
 }
 uint address = (uint)DAT_0052c270.buffer;
 Header expected = *(Header *)(address + footer - offset);
 Header actual;
 DAT_0052c270.file = file;
 DAT_0052c270.block = block;
 if (!FUN_002781c0(length, &actual)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
 for (int i = 0; i < 5; ++i) if (actual.word[i] != expected.word[i]) { error = 12; return false; }
 DAT_0052c270.valid = 1;
 return true;
}