// STATUS: equivalent (tools/equiv.py level 3: 19971 inputs, branch coverage 16/16)
// FUN_001f3af0 @ 0x001f3af0
#include "decls/data/game/global.h"
struct Item_1f3af0 { void FUN_001e8ac0(); };
struct State_1f3af0 {
 char pad0[4]; void* handle; Item_1f3af0* item; char padC[8]; bool active;
 void FUN_001f3400(int);
 void FUN_001f32b0(Item_1f3af0*,int,int);
 void FUN_001f3370(void*);
};
struct Input_1f3af0 { char pad[0x6c]; float value; };
extern bool __cdecl FUN_00249b40(void*);
extern void __cdecl FUN_0024af00(void*);
extern void __cdecl FUN_00247890(void*,float);
struct Object {
 char pad0[0xc8]; State_1f3af0* state; char padCC[0x334-0xcc]; float scale;
 bool run(Item_1f3af0*,void*,Input_1f3af0*);
};
bool Object::run(Item_1f3af0* item,void* arg,Input_1f3af0* input) {
 if (!state || !item) return false;
 if (state->handle && !FUN_00249b40(state->handle)) return false;
 if (input->value > 75.0f) return false;
 if (state->item) {
  if (state->item != item) {
   state->FUN_001f3400(250);
   state->item->FUN_001e8ac0();
   state->item=0;
   FUN_0024af00(state->handle);
   state->handle=0;
   state->active=false;
   state->FUN_001f32b0(item,0,0);
  }
 } else state->FUN_001f32b0(item,0,0);
 if(state->handle) FUN_00247890(state->handle,DAT_004c7df8 * scale * 0.01f);
 state->FUN_001f3370(arg);
 return true;
}
