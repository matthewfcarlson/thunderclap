// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00014fe0..0x000151a0 (kind game, layer game, confidence high), dominant class CSweepAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0a1bcad {
#define TREE_TU_END }
namespace fn_f0a1bcad {} using namespace fn_f0a1bcad;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0a1bcad {
struct Sweep_14fe0;
struct Manager_14fe0 { void FUN_00222890(Sweep_14fe0*, float, unsigned, float, unsigned, unsigned, float); };
struct Context_14fe0 { Manager_14fe0* FUN_00059a40(); };
struct Owner_14fe0 {  };
struct Params_14fe0 { char pad[0x18]; unsigned x,y,z; };
struct Name_14fe0 { unsigned data;  };
struct Sweep_14fe0 { virtual void slot0(); char pad[4]; Name_14fe0 name; char pad2[8]; unsigned kind; Sweep_14fe0* FUN_002248f0(int); };
extern void* __cdecl FUN_00263ea0(unsigned);
struct R_15170 {
    void call_00222970(void*, int);
};
extern void* __fastcall FUN_000592a0(void*);
extern "C" R_15170* __fastcall FUN_00059a40(void*);

} // namespace fn_f0a1bcad

// 0x00014fe0 CSweepAction::vfunc_6 (167 B): equivalent/0x00014fe0.cpp
// sym: ?vfunc_6@CSweepAction@@UAE_NH@Z @5a7b89ef0a7d @w374016a96fba
// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 4/4)
// CSweepAction::vfunc_6 @ 0x00014fe0
bool CSweepAction::vfunc_6(int __p0) {
 Manager_14fe0* m = ((Context_14fe0 *)((owners::Object_592a0 *)((*(Owner_14fe0 * *)&this->f_1c)))->FUN_000592a0())->FUN_00059a40();
 if (!m) return false;
 unsigned x=(*(Params_14fe0 * *)&this->f_20)->x,y=(*(Params_14fe0 * *)&this->f_20)->y,z=(*(Params_14fe0 * *)&this->f_20)->z;
 Sweep_14fe0* s=(Sweep_14fe0*)FUN_00263ea0(0x70);
 if(s) s=s->FUN_002248f0(0);
 (*(Sweep_14fe0 * *)&this->f_24)=s;
 ((owners::Target_27b040 *)&(s->name))->FUN_0027b040((hulk_uintptr)"sweep");
 (*(Sweep_14fe0 * *)&this->f_24)->slot0();
 (*(Sweep_14fe0 * *)&this->f_24)->kind=2;
 m->FUN_00222890((*(Sweep_14fe0 * *)&this->f_24),-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}


// 0x00015090 CSweepAction::vfunc_7 (212 B): equivalent/0x00015090.cpp [wrapped: conflict: CSweepAction]
// sym: ?vfunc_7@CSweepAction@fn_00015090@@UAE_NM@Z @d8f0189623c2 @we762f68ebc27
namespace fn_00015090 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// CSweepAction::vfunc_7 @ 0x00015090
struct Value_15090 { hulk_freg FUN_000354c0(); };
struct Link_15090 { Value_15090* FUN_00059a30(); };
struct Actor_15090 { Link_15090* FUN_000592a0(); };
struct Timing_15090 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7();
 char pad[16]; float duration;
};
struct Output_15090 { void FUN_00221d20(float); };
struct Destination_15090 { char pad[24]; Output_15090 output; };
struct CSweepAction {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual bool vfunc_7(float); virtual void slot8();
 char pad[24]; Actor_15090* actor; Timing_15090* timing; Destination_15090* destination; float progress;
};
bool CSweepAction::vfunc_7(float step) {
 if (!destination) return false;
 float base = actor->FUN_000592a0()->FUN_00059a30()->FUN_000354c0();
 float duration = timing->duration;
 float rate = timing->slot7();
 if (rate <= 0.0f) { destination->output.FUN_00221d20(duration + base); return false; }
 step = (duration / rate) * step;
 if (duration < 0.0f) {
  if (step + progress < duration) step = duration - progress;
 } else {
  if (step + progress > duration) step = duration - progress;
 }
 destination->output.FUN_00221d20(step + base);
 progress = step + progress;
 return true;
}
} // namespace fn_00015090


// 0x00015170 CSweepAction::vfunc_4 (37 B): matches/0x00015170.cpp
// sym: ?vfunc_4@CSweepAction@@UAEXXZ
// Same code shape as 0x00013b40 (propagated; names are from that function)
void CSweepAction::vfunc_4() {
    void* a = FUN_000592a0((*(void * *)&this->f_1c));
    R_15170* b = FUN_00059a40(a);
    if (b)
        b->call_00222970((*(void * *)&this->f_24), 0);
}

