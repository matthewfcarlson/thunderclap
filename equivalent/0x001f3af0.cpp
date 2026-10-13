// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 16/16)
// FUN_001f3af0 @ 0x001f3af0
struct Item { void FUN_001e8ac0(); };
struct State {
 char pad0[4]; void* handle; Item* item; char padC[8]; bool active;
 void FUN_001f3400(int);
 void FUN_001f32b0(Item*,int,int);
 void FUN_001f3370(void*);
};
struct Input { char pad[0x6c]; float value; };
extern bool __cdecl FUN_00249b40(void*);
extern void __cdecl FUN_0024af00(void*);
extern void __cdecl FUN_00247890(void*,float);
struct Object {
 char pad0[0xc8]; State* state; char padCC[0x334-0xcc]; float scale;
 bool run(Item*,void*,Input*);
};
bool Object::run(Item* item,void* arg,Input* input) {
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
 if(state->handle) FUN_00247890(state->handle,100.0f * scale * 0.01f);
 state->FUN_001f3370(arg);
 return true;
}
