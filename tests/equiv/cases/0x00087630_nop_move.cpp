// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 36/36)
// FUN_00087630 @ 0x00087630
struct Target;
struct Queue { void FUN_0008db00(); bool FUN_0008db20(Target*); };
bool __cdecl FUN_0008db80(); void __cdecl FUN_0008db90();
struct State { int mode; int unused; int saved; };
struct Clock { char pad[32]; unsigned __int64 ticks; void FUN_00086450(); float FUN_000860c0(); };
struct Sim { char pad[44]; void* item; void FUN_00088c30(State*,float); int FUN_00088e40(); };
struct Notify { void FUN_000afe80(); };
struct Sub { char pad[24]; Notify* notify; };
struct Root { char pad[84]; Sub* sub; }; extern Root* DAT_004dd700;
struct Stop { void FUN_001b7970(); };
struct Update { void FUN_001eb2a0(float,int); };
struct Check { bool FUN_00089e80(void*,unsigned int); };
struct UI { void FUN_0023f6b0(); void FUN_0023f720(int*,int); bool FUN_0023f760(const char*,int,int); void FUN_0023f740(); void FUN_0023f6c0(); }; extern UI* DAT_004dd6e8; extern int DAT_0049c218;
struct Gate { unsigned int FUN_000b4f20(); }; struct GateRoot { char pad[32]; Gate* gate; }; extern GateRoot* DAT_004dd6ec;
struct Audio { void FUN_001d1160(float); void FUN_001d15d0(int); }; Audio* __cdecl FUN_001d4c90();
unsigned int __cdecl FUN_00267f80(); unsigned int __cdecl FUN_00267f00(); float __cdecl FUN_00085e60(unsigned int,int); void __cdecl FUN_00240bb0();
extern unsigned char DAT_004dd8e4, DAT_0049caa0; extern float DAT_004dd914;
struct Target { char pad0[4]; State* state; Clock* clock; Sim* sim; char pad10[12]; Queue* queue; char pad20[16]; Update* update; Stop* stop; Check* check; void FUN_00086ad0(); void FUN_00086790(); void FUN_000873a0(); void FUN_00086a40(float); void run(); };
void Target::run() {
 queue->FUN_0008db00();
 if (!queue->FUN_0008db20(this)) { if(state->mode==7) stop->FUN_001b7970(); else if(state->mode==6) { state->mode=state->saved; state->saved=0; DAT_004dd700->sub->notify->FUN_000afe80(); } state->mode=8; DAT_004dd700->sub->notify->FUN_000afe80(); }
 if(queue && FUN_0008db80()) { do { FUN_0008db90(); queue->FUN_0008db00(); } while(FUN_0008db80()); }
 FUN_00086ad0(); if(state->mode==3) { FUN_00086790(); return; }
 clock->FUN_00086450(); FUN_000873a0();
 if(state->mode!=7) { Audio* a=FUN_001d4c90(); a->FUN_001d1160(clock->ticks * 0.000001f); a->FUN_001d15d0(0); }
 unsigned int start=FUN_00267f80(); FUN_00086a40(clock->ticks * 0.000001f);
 if(state->mode==8) return;
 unsigned int start2=0; if(DAT_004dd8e4) start2=FUN_00267f00();
 if(state->mode==4) { DAT_004dd6e8->FUN_0023f6b0(); DAT_004dd6e8->FUN_0023f720(&DAT_0049c218,0); if(DAT_004dd6e8->FUN_0023f760("Enable simulation",83,1)) { float v=clock->FUN_000860c0(); sim->FUN_00088c30(state,v); } DAT_004dd6e8->FUN_0023f740(); void* item=sim->item; unsigned int result=DAT_004dd6ec->gate->FUN_000b4f20(); unsigned int disabled=(result & 0xffffff00u) | ((result & 255u)==0 ? 1u:0u); if(check->FUN_00089e80(item,disabled)) { state->mode=5; DAT_004dd700->sub->notify->FUN_000afe80(); } DAT_004dd6e8->FUN_0023f6c0(); if(sim->FUN_00088e40()) { state->mode=5; DAT_004dd700->sub->notify->FUN_000afe80(); return; } }
 unsigned int end=FUN_00267f80(); unsigned __int64 elapsed=(unsigned __int64)end-(unsigned __int64)start; update->FUN_001eb2a0(elapsed*0.001f,1);
 if(DAT_004dd8e4) { unsigned int e=FUN_00267f00(); if(DAT_004dd8e4) DAT_004dd914=FUN_00085e60(e-start2,0); }
 if(DAT_0049caa0 && state->mode!=7) FUN_00240bb0();
}