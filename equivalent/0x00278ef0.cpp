// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 25/28, incomplete)
// FUN_00278ef0 @ 0x00278ef0
typedef unsigned int uint;
struct Obj { char pad[0xb4]; uint error; bool FUN_00278de0(); uint FUN_002787c0(uint); void FUN_002789e0(uint); bool FUN_00278ef0(uint source, uint length, bool flag); };
extern unsigned char *DAT_0052c270;
extern uint DAT_0052c274, DAT_0052c278, DAT_0052c27c;
namespace XAPILIB { extern "C" uint __stdcall XCalculateSignatureBegin(uint); extern "C" uint __stdcall GetLastError(); }
extern "C" void __stdcall FUN_002120f5(uint, void *, uint);
extern "C" void __stdcall FUN_00212143(uint, void *);
extern "C" uint __stdcall FUN_002101d4(uint, uint, uint, uint);
extern "C" uint __stdcall FUN_0021007a(uint, void *, uint, uint *, uint);
extern "C" bool __cdecl FUN_00278180(void *, uint, void *);
struct Signature { uint word[5]; };
bool Obj::FUN_00278ef0(uint source, uint length, bool flag) {
 if (!FUN_00278de0()) return false;
 DAT_0052c27c = 0;
 unsigned char *buffer = DAT_0052c270;
 for (uint i=0;i<8192;++i) buffer[i]=0;
 uint remaining=length;
 if (flag) *(uint *)DAT_0052c270=length;
 Signature sig;
 if (length>8192) {
  unsigned char *signBuffer=DAT_0052c270;
  uint h=XAPILIB::XCalculateSignatureBegin(0);
  if(h==0xffffffff) { error=FUN_002787c0(XAPILIB::GetLastError()); return false; }
  FUN_002120f5(h,signBuffer,8172);
  FUN_00212143(h,&sig);
  for(int j=0;j<5;++j) ((uint *)(DAT_0052c270+8172))[j]=sig.word[j];
 }
 if(FUN_002101d4(source,0,0,0)) { error=FUN_002787c0(XAPILIB::GetLastError()); return false; }
 uint count=0, read;
 while(remaining>8192) {
  if(!FUN_0021007a(source,DAT_0052c270,8192,&read,0)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  if(count==0 && flag) {
   *(uint *)DAT_0052c270=0;
   unsigned char *signBuffer=DAT_0052c270;
   uint h=XAPILIB::XCalculateSignatureBegin(0);
   if(h==0xffffffff) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
   FUN_002120f5(h,signBuffer,8172);
   FUN_00212143(h,&sig);
   for(int j=0;j<5;++j) ((uint *)(DAT_0052c270+8172))[j]=sig.word[j];
  }
  remaining-=8192;
  ++count;
 }
 if(remaining) {
  *(uint *)DAT_0052c270=0;
  if(!FUN_00278180(DAT_0052c270,remaining-20,&sig)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  for(int j=0;j<5;++j) ((uint *)(DAT_0052c270+remaining-20))[j]=sig.word[j];
  if(!FUN_0021007a(source,DAT_0052c270,remaining,&read,0)) { FUN_002789e0(XAPILIB::GetLastError()); return false; }
  ++count;
 }
 DAT_0052c274=source;
 DAT_0052c278=count-1;
 DAT_0052c27c=1;
 return true;
}