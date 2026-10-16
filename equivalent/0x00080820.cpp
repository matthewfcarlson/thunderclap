// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00080820 @ 0x00080820
#include "decls/data/game/global.h"

extern unsigned int DAT_004d9968;
extern void __fastcall __security_check_cookie(unsigned int);
extern int __cdecl FUN_000964a0(char*, unsigned int, const char*, ...);
struct Actor_80820 {
 bool FUN_0007a420(int*, int*, int*, int*);
 int FUN_0007a8f0(int*, int*);
 int FUN_0007f560(const char*, int, int, int, int);
 int FUN_0007f690(const char*, int, int, int);
 int FUN_00080820();
};
int Actor_80820::FUN_00080820() {
 int a,b,c,d;
 char name[32];
 volatile unsigned int cookie=DAT_004d9968;
 int result;
 if (FUN_0007a420(&a,&c,&d,&b)) {
  ++(*(int*)&DAT_004dd078);
  FUN_000964a0(name,32,"civilian%d",(*(int*)&DAT_004dd078));
  result=FUN_0007f560(name,a,c,d,b);
 } else {
  int index=FUN_0007a8f0(&a,&b);
  result=index;
  if(index!=-1) {
   ++(*(int*)&DAT_004dd078);
   FUN_000964a0(name,32,"civilian%d",(*(int*)&DAT_004dd078));
   result=FUN_0007f690(name,index,a,b);
  }
 }
 __security_check_cookie(cookie);
 return result;
}
