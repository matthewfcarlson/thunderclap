// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 23/24, incomplete)
// FUN_001e9bf0 @ 0x001e9bf0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
struct Clock_1e9bf0 { float FUN_001e8730(); };
struct Entry_1e9bf0 { int state; int unused; unsigned int amount; int blockedC; int blocked10; void FUN_001e8d40(); };
struct Worker_1e9bf0 { bool FUN_00266750(); void FUN_00263e90(); };
struct Item_1e9bf0 { void FUN_000bd1b0(int); };
struct Manager_1e9bf0 { Item_1e9bf0* FUN_00086280(); };
struct World { char pad[0x54]; Manager_1e9bf0* manager; };
void __cdecl FUN_002656a0();
void __cdecl thunk_FUN_00270a50();
struct Owner_1e9bf0 { char pad[0x29]; bool done; char pad2[2]; Entry_1e9bf0* entries[64]; int count; bool FUN_001e9bf0(); };
bool Owner_1e9bf0::FUN_001e9bf0() {
 for(int i=0;i<count;++i) {
  Entry_1e9bf0* e=entries[i];
  if(e && !e->blocked10 && !e->blockedC) {
   int raw=(int)e->amount;
   float amount=raw<0 ? (double)raw+DAT_003f3f18 : (double)raw;
   float available=(*(Clock_1e9bf0**)&DAT_004e3690)->FUN_001e8730();
   e=entries[i];
   if(available<=amount) {
    int v=(int)e->amount;
    (*(float*)&DAT_004e36ac)=(v<0 ? (double)v+DAT_003f3f18 : (double)v)+(*(float*)&DAT_004e36ac);
   } else {
    e->FUN_001e8d40();
    while(entries[i]->state!=3) {
     FUN_002656a0();
     thunk_FUN_00270a50();
     DAT_004dd700->manager->FUN_00086280()->FUN_000bd1b0(0);
     Entry_1e9bf0* current=entries[i];
     if(current->state==1 && (*(Worker_1e9bf0**)&DAT_004e3694)->FUN_00266750()) {
      current->state=3;
      (*(Worker_1e9bf0**)&DAT_004e3694)->FUN_00263e90();
      (*(Worker_1e9bf0**)&DAT_004e3694)=0;
     }
    }
   }
  }
 }
 done=true;
 return true;
}
