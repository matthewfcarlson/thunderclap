// STATUS: equivalent (tools/equiv.py level 3: 20019 inputs, branch coverage 11/12, incomplete)
// FUN_001e8d40 @ 0x001e8d40
// cl-flags: /GS
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
struct Manager_1e8d40 { void FUN_00265920(char *, int *, int); };
struct Clip {
 int active;
 int reserved;
 unsigned int size;
 int reserved2;
 unsigned int kind;
 void FUN_001e8d40();
};
void Clip::FUN_001e8d40() {
 if (active == 0 && (*(int*)&DAT_004e3694) == 0) {
 char name[16];
 sprintf(name, "%d.%s", this, "clips");
 (*(Manager_1e8d40**)&DAT_00527c58)->FUN_00265920(name, ((int*)&DAT_004e3694), 1);
 unsigned int type = kind;
 active = 1;
 double amount = (int)size;
 if ((int)size < 0) amount += 4294967296.0f;
 if (type > 0) DAT_004e369c = amount + DAT_004e369c;
 else DAT_004e36a0 = amount + DAT_004e36a0;
 }
}
