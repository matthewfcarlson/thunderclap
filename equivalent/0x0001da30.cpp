// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CDamageAction::vfunc_7 @ 0x0001da30
struct Source_1da30 { char pad[0x12c]; unsigned id; char pad2[0x1e58-0x130]; float factor; };
struct Info_1da30 { char pad[0x4c]; unsigned id; char pad2[0x7c-0x50]; float factor; char pad3[0x91-0x80]; unsigned char flag; };
struct Actor_1da30 { char pad[0x12c]; unsigned id; char pad2[0x334-0x130]; Source_1da30* secondary; Source_1da30* primary; void FUN_00043350(float, unsigned, int, float, int, unsigned); };
struct Intermediate_1da30 { Actor_1da30* FUN_00059a30(); };
struct Owner_1da30 { virtual void v0(); virtual void v1(); virtual void v2(); virtual Info_1da30* v3(); Intermediate_1da30* FUN_000592a0(); };
void __cdecl FUN_001eb210();
struct CDamageAction { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual bool vfunc_7(int); char pad[0x1c-4]; Owner_1da30* owner; float low; float high; };
bool CDamageAction::vfunc_7(int) { Actor_1da30* actor=owner->FUN_000592a0()->FUN_00059a30(); unsigned id=0; union { unsigned word; unsigned char byte; } flag; flag.byte=0; float factor=0.0f; if(actor->primary) { id=actor->primary->id; factor=actor->primary->factor; } else if(actor->secondary) { id=actor->secondary->id; factor=actor->secondary->factor; } else { Info_1da30* info=owner->v3(); if(info) { id=info->id; if(id==actor->id) id=0; flag.byte=info->flag; factor=info->factor; } } float result=low; if(high>low) { if(!(factor>=0.0f && factor<=1.0f)) factor=factor>1.0f ? 1.0f:0.0f; result=low+(high-low)*factor; } actor->FUN_00043350(result,id,0,1.0f,0,flag.word); FUN_001eb210(); return false; }