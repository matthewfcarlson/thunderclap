// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001eb060 @ 0x001eb060
#include "decls/data/game/global.h"

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl sprintf(char *, const char *, ...);
struct Manager_1eb060 {
 char pad[0x514];
 int mainMix;
 char pad518[8];
 unsigned char loaded;
 void FUN_001eab10(const char *);
 int FUN_001e9960(const char *);
 void FUN_001e9a90(const char *, int);
 void target(const char *first, const char *second);
};
void Manager_1eb060::target(const char *first, const char *second) {
 unsigned int cookie = DAT_004d9968;
 char firstPath[32];
 char secondPath[32];
 (*(int*)&DAT_004e36ac) = 0;
 if (DAT_0049caa0 && !loaded) {
  if (!second) {
   FUN_001eab10("scripts\\frontend.p3d");
  } else {
   FUN_001eab10("scripts\\common.p3d");
   sprintf(firstPath, "scripts\\%s.p3d", first);
   FUN_001eab10(firstPath);
   sprintf(secondPath, "scripts\\%s.p3d", second);
   FUN_001eab10(secondPath);
  }
  loaded = 1;
 }
 mainMix = FUN_001e9960("main_mix");
 FUN_001e9a90("main_mix", 0);
 __security_check_cookie(cookie);
}
