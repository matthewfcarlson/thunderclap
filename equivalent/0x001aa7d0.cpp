// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 19/20, incomplete)
// FUN_001aa7d0 @ 0x001aa7d0
// cl-flags: /GS
#include "decls/data/game/hulkfight/scenario.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
struct Resource_1aa7d0 {
 char pad[0x4c]; const char *name; char pad50[2]; unsigned char special; char pad53; unsigned int option;
};
struct Controller_1aa7d0 {
 void FUN_00207960(const char *, unsigned int, int);
 const char *FUN_00203840();
 void FUN_002078d0();
};
struct Object {
 char pad[0x1c]; Resource_1aa7d0 *resource; char pad20[0x1ec]; Controller_1aa7d0 *controller;
 void FUN_001aa150(); void FUN_001aa2a0(); void FUN_001a9f10();
 bool FUN_001aa7d0();
};
bool Object::FUN_001aa7d0() {
 char path[256];
 const char *name=resource->name;
 if (!name) { return false; }
 unsigned int length=0;
 while(name[length]) ++length;
 if(length<=1) { return false; }
 sprintf(path,"nis/%s",name);
 if(resource->special) controller->FUN_00207960(path,resource->option,0);
 else {
 const char *current=controller->FUN_00203840();
 if(current) {
 unsigned int i=0;
 while((unsigned char)current[i]==(unsigned char)path[i] && current[i]) ++i;
 if((unsigned char)current[i]==(unsigned char)path[i]) controller->FUN_002078d0();
 }
 }
 FUN_001aa150(); FUN_001aa2a0(); FUN_001a9f10();
 (*(unsigned char*)&DAT_004e1764)=1;
 return true;
}