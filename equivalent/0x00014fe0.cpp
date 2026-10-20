// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 4/4)
// CSweepAction::vfunc_6 @ 0x00014fe0
#include "gen/global.h"

struct Sweep_14fe0;
struct Manager_14fe0 { void FUN_00222890(Sweep_14fe0*, float, unsigned, float, unsigned, unsigned, float); };
struct Context_14fe0 { Manager_14fe0* FUN_00059a40(); };
struct Owner_14fe0 { Context_14fe0* FUN_000592a0(); };
struct Params_14fe0 { char pad[0x18]; unsigned x,y,z; };
struct Name_14fe0 { unsigned data; void FUN_0027b040(const char*); };
struct Sweep_14fe0 { virtual void slot0(); char pad[4]; Name_14fe0 name; char pad2[8]; unsigned kind; Sweep_14fe0* FUN_002248f0(int); };
extern void* __cdecl FUN_00263ea0(unsigned);

bool CSweepAction::vfunc_6(int __p0) {
 Manager_14fe0* m = (*(Owner_14fe0 * *)&this->f_1c)->FUN_000592a0()->FUN_00059a40();
 if (!m) return false;
 unsigned x=(*(Params_14fe0 * *)&this->f_20)->x,y=(*(Params_14fe0 * *)&this->f_20)->y,z=(*(Params_14fe0 * *)&this->f_20)->z;
 Sweep_14fe0* s=(Sweep_14fe0*)FUN_00263ea0(0x70);
 if(s) s=s->FUN_002248f0(0);
 (*(Sweep_14fe0 * *)&this->f_24)=s;
 s->name.FUN_0027b040("sweep");
 (*(Sweep_14fe0 * *)&this->f_24)->slot0();
 (*(Sweep_14fe0 * *)&this->f_24)->kind=2;
 m->FUN_00222890((*(Sweep_14fe0 * *)&this->f_24),-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}
