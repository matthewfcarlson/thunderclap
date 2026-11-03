// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001eb060 @ 0x001eb060
// cl-flags: /GS
#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
void owners::Manager_1eb060::FUN_001eb060(const char *first, const char *second) {
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
}
