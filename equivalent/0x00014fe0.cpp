// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// CSweepAction::vfunc_6 @ 0x00014fe0
struct Sweep;
struct Manager { void FUN_00222890(Sweep*, float, unsigned, float, unsigned, unsigned, float); };
struct Context { Manager* FUN_00059a40(); };
struct Owner { Context* FUN_000592a0(); };
struct Params { char pad[0x18]; unsigned x,y,z; };
struct Name { unsigned data; void FUN_0027b040(const char*); };
struct Sweep { virtual void slot0(); char pad[4]; Name name; char pad2[8]; unsigned kind; Sweep* FUN_002248f0(int); };
extern void* __cdecl FUN_00263ea0(unsigned);
struct CSweepAction { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual bool vfunc_6(unsigned); char pad[0x18]; Owner* owner; Params* params; Sweep* sweep; };
bool CSweepAction::vfunc_6(unsigned) {
 Manager* m = owner->FUN_000592a0()->FUN_00059a40();
 if (!m) return false;
 unsigned x=params->x,y=params->y,z=params->z;
 Sweep* s=(Sweep*)FUN_00263ea0(0x70);
 if(s) s=s->FUN_002248f0(0);
 sweep=s;
 s->name.FUN_0027b040("sweep");
 sweep->slot0();
 sweep->kind=2;
 m->FUN_00222890(sweep,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}