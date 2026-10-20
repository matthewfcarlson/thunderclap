// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 25/28, incomplete)
// FUN_00278ef0 @ 0x00278ef0
#include "compat/ptr.h"
#include "decls/data/platform/xbox/core.h"

typedef unsigned int uint_278ef0;
struct Obj_278ef0 { char pad[0xb4]; uint_278ef0 error; bool FUN_00278de0(); uint_278ef0 FUN_002787c0(hulk_uintptr); void FUN_002789e0(hulk_uintptr); bool FUN_00278ef0(uint_278ef0 source, uint_278ef0 length, bool flag); };
namespace XAPILIB { extern "C" uint_278ef0 __stdcall XCalculateSignatureBegin(uint_278ef0); extern "C" hulk_uintptr __stdcall GetLastError(); }
extern "C" void __stdcall FUN_002120f5(uint_278ef0, void *, uint_278ef0);
extern "C" void __stdcall FUN_00212143(uint_278ef0, void *);
extern "C" uint_278ef0 __stdcall FUN_002101d4(uint_278ef0, hulk_uintptr, uint_278ef0, uint_278ef0);
extern "C" uint_278ef0 __stdcall FUN_0021007a(uint_278ef0, void *, uint_278ef0, uint_278ef0 *, uint_278ef0);
extern "C" bool __cdecl FUN_00278180(void *, uint_278ef0, void *);
struct Signature { uint_278ef0 word[5]; };
bool Obj_278ef0::FUN_00278ef0(uint_278ef0 source, uint_278ef0 length, bool flag) {
 if (!FUN_00278de0()) return false;
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 12)) = 0;
 unsigned char *buffer = (*(unsigned char**)&DAT_0052c270);
 for (uint_278ef0 i=0;i<8192;++i) buffer[i]=0;
 uint_278ef0 remaining=length;
 if (flag) *(uint_278ef0 *)(*(unsigned char**)&DAT_0052c270)=length;
 Signature sig;
 if (length>8192) {
  unsigned char *signBuffer=(*(unsigned char**)&DAT_0052c270);
  uint_278ef0 h=XAPILIB::XCalculateSignatureBegin(0);
  if(h==0xffffffff) { error=FUN_002787c0(XAPILIB::GetLastError()); return false; }
  FUN_002120f5(h,signBuffer,8172);
  FUN_00212143(h,&sig);
  for(int j=0;j<5;++j) ((uint_278ef0 *)((*(unsigned char**)&DAT_0052c270)+8172))[j]=sig.word[j];
 }
 if(FUN_002101d4(source,0,0,0)) { error=FUN_002787c0(XAPILIB::GetLastError()); return false; }
 uint_278ef0 count=0, read;
 while(remaining>8192) {
  if(!FUN_0021007a(source,(*(unsigned char**)&DAT_0052c270),8192,&read,0)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  if(count==0 && flag) {
   *(uint_278ef0 *)(*(unsigned char**)&DAT_0052c270)=0;
   unsigned char *signBuffer=(*(unsigned char**)&DAT_0052c270);
   uint_278ef0 h=XAPILIB::XCalculateSignatureBegin(0);
   if(h==0xffffffff) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
   FUN_002120f5(h,signBuffer,8172);
   FUN_00212143(h,&sig);
   for(int j=0;j<5;++j) ((uint_278ef0 *)((*(unsigned char**)&DAT_0052c270)+8172))[j]=sig.word[j];
  }
  remaining-=8192;
  ++count;
 }
 if(remaining) {
  *(uint_278ef0 *)(*(unsigned char**)&DAT_0052c270)=0;
  if(!FUN_00278180((*(unsigned char**)&DAT_0052c270),remaining-20,&sig)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  for(int j=0;j<5;++j) ((uint_278ef0 *)((*(unsigned char**)&DAT_0052c270)+remaining-20))[j]=sig.word[j];
  if(!FUN_0021007a(source,(*(unsigned char**)&DAT_0052c270),remaining,&read,0)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  ++count;
 }
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 4))=source;
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 8))=count-1;
 (*(uint_278ef0*)((char*)&DAT_0052c270 + 12))=1;
 return true;
}