// STATUS: equivalent (tools/equiv.py level 3: 10038 inputs, branch coverage 4/4)
// FUN_00080820 @ 0x00080820
#include "decls/data/game/global.h"

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern int __cdecl FUN_000964a0(char*, unsigned int, const char*, ...);
struct Actor_80820 {
 bool FUN_0007a420(int*, int*, int*, int*);
 int FUN_0007a8f0(int*, int*);
 int FUN_0007f560(const char*, int, int, int, int);
 int FUN_0007f690(const char*, int, int, int);
 int FUN_00080820();
};
// The original's frame: four out-ints, the name buffer, then the /GS cookie directly above it.
struct Frame_80820 { int a, b, c, d; char name[32]; unsigned int cookie; };
int Actor_80820::FUN_00080820() {
 Frame_80820 fr;
 fr.cookie=DAT_004d9968;
 int result;
 if (FUN_0007a420(&fr.a,&fr.c,&fr.d,&fr.b)) {
  ++(*(int*)&DAT_004dd078);
  FUN_000964a0(fr.name,32,"civilian%d",(*(int*)&DAT_004dd078));
  result=FUN_0007f560(fr.name,fr.a,fr.c,fr.d,fr.b);
 } else {
  int index=FUN_0007a8f0(&fr.a,&fr.b);
  result=index;
  if(index!=-1) {
   ++(*(int*)&DAT_004dd078);
   FUN_000964a0(fr.name,32,"civilian%d",(*(int*)&DAT_004dd078));
   result=FUN_0007f690(fr.name,index,fr.a,fr.b);
  }
 }
 __security_check_cookie(fr.cookie);
 return result;
}
