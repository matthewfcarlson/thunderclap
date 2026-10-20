// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 14/16, incomplete)
// fight::BinReader::vfunc_7 @ 0x0023bf10
#include "compat/ptr.h"
struct Stream {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual int FUN_read(void*, unsigned);
};
struct Value_23bf10 { void FUN_0027af60(unsigned, unsigned); void FUN_0027b040(const char*); };
extern "C" void* __cdecl FUN_00238190(int);
extern "C" char* __cdecl FUN_00266e00(void*, hulk_uintptr);
extern "C" void __cdecl FUN_00267090(void*);
namespace fight {
struct BinReader {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 virtual bool vfunc_7(unsigned a, unsigned b, Value_23bf10* out);
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(unsigned,unsigned,unsigned*);
 char pad4[4]; Stream* stream; char padc; unsigned char reverse; unsigned char binary; char padf; int length; char pad14[12]; unsigned remaining;
};
bool BinReader::vfunc_7(unsigned a, unsigned b, Value_23bf10* out) {
 if(binary) {
  union { unsigned words[2]; unsigned char bytes[8]; } data;
  unsigned amount=remaining; if(amount>8) amount=8;
  int n=stream->FUN_read(&data,amount);
  bool ok=n==8;
  remaining-=amount;
  if(reverse) { for(int i=0;i<4;++i) { unsigned char t=data.bytes[i]; data.bytes[i]=data.bytes[7-i]; data.bytes[7-i]=t; } }
  out->FUN_0027af60(data.words[0],data.words[1]);
  return ok;
 }
 vfunc_12(a,b,&a);
 bool ok=true;
 if(length>0) {
  unsigned rounded=(unsigned(length)+3)&~3u;
  char* buf=FUN_00266e00(FUN_00238190(1),rounded+1);
  unsigned amount=remaining; if(rounded<amount) amount=rounded;
  int n=stream->FUN_read(buf,amount);
  remaining-=amount;
  ok=unsigned(n)==rounded;
  buf[length]=0;
  out->FUN_0027b040(buf);
  FUN_00267090(buf);
 } else { out->FUN_0027b040(0); }
 length=-1;
 return ok;
}
}