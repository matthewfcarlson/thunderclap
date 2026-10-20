// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 14/14)
// FUN_001b4620 @ 0x001b4620
#include "decls/address.h"
struct Vec3_1b4620 { float x,y,z; };
struct State_1b4620 { int FUN_00088fa0(); int FUN_00088fb0(); };
struct ContextResult { char pad[0x80]; State_1b4620 state; };
struct Context { ContextResult* FUN_00086310(); };
struct World { char pad[0x54]; Context* context; };
struct Slot_1b4620 { char pad[0xc]; int status; char rest[0x128]; void FUN_001b3040(Vec3_1b4620 position, unsigned int a); void FUN_001b3760(unsigned int b); void FUN_001b32e0(unsigned int b); };
struct Owner_1b4620 { char pad[0x10]; Slot_1b4620 slots[4]; bool FUN_001b4620(Vec3_1b4620 position, unsigned int a, unsigned int b, unsigned int c); };
bool Owner_1b4620::FUN_001b4620(Vec3_1b4620 position, unsigned int a, unsigned int b, unsigned int c) {
 State_1b4620* state = &DAT_004dd700->context->FUN_00086310()->state;
 if (state->FUN_00088fa0()==10) { if (state->FUN_00088fb0()==39) return false; if(state->FUN_00088fb0()==45) return false; }
 for(int i=0;i<4;++i) { Slot_1b4620* slot=&slots[i]; if(slot->status<0) { slot->FUN_001b3040(position,a); slot->FUN_001b3760(c); if(b) slot->FUN_001b32e0(b); if(c) slot->FUN_001b32e0(c); return true; } }
 return false;
}