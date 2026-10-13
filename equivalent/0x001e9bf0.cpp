// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 23/24, incomplete)
// FUN_001e9bf0 @ 0x001e9bf0
struct Clock { float FUN_001e8730(); };
struct Entry { int state; int unused; unsigned int amount; int blockedC; int blocked10; void FUN_001e8d40(); };
struct Worker { bool FUN_00266750(); void FUN_00263e90(); };
struct Item { void FUN_000bd1b0(int); };
struct Manager { Item* FUN_00086280(); };
struct Root { char pad[0x54]; Manager* manager; };
extern Clock* DAT_004e3690;
extern Worker* DAT_004e3694;
extern Root* DAT_004dd700;
extern float DAT_004e36ac;
extern const float DAT_003f3f18;
void __cdecl FUN_002656a0();
void __cdecl thunk_FUN_00270a50();
struct Owner { char pad[0x29]; bool done; char pad2[2]; Entry* entries[64]; int count; bool FUN_001e9bf0(); };
bool Owner::FUN_001e9bf0() {
 for(int i=0;i<count;++i) {
  Entry* e=entries[i];
  if(e && !e->blocked10 && !e->blockedC) {
   int raw=(int)e->amount;
   float amount=raw<0 ? (double)raw+DAT_003f3f18 : (double)raw;
   float available=DAT_004e3690->FUN_001e8730();
   e=entries[i];
   if(available<=amount) {
    int v=(int)e->amount;
    DAT_004e36ac=(v<0 ? (double)v+DAT_003f3f18 : (double)v)+DAT_004e36ac;
   } else {
    e->FUN_001e8d40();
    while(entries[i]->state!=3) {
     FUN_002656a0();
     thunk_FUN_00270a50();
     DAT_004dd700->manager->FUN_00086280()->FUN_000bd1b0(0);
     Entry* current=entries[i];
     if(current->state==1 && DAT_004e3694->FUN_00266750()) {
      current->state=3;
      DAT_004e3694->FUN_00263e90();
      DAT_004e3694=0;
     }
    }
   }
  }
 }
 done=true;
 return true;
}
