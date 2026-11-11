// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00017870..0x000179b0 (kind game, layer game, confidence medium), dominant class CHapticEventAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff7d2848 {
#define TREE_TU_END }
namespace fn_ff7d2848 {} using namespace fn_ff7d2848;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff7d2848 {
struct Gate_17870 { bool FUN_00099740(); };
} // namespace fn_ff7d2848
struct World { char pad[8]; Gate_17870* gate; };
namespace fn_ff7d2848 {
struct Motors { char pad[16]; int count; void FUN_000af530(int index,int channel,float value);  };
struct Controller_17870 {  float FUN_000afe60(); float FUN_000afe70(); };
} // namespace fn_ff7d2848
struct Singleton_4dd6ec { Controller_17870* FUN_00086330(); };
namespace fn_ff7d2848 {
struct Event_17870 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual float start(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual float end();
 char pad[16]; float strength0; float strength1;
};
class A_17980 {
  public:
    void* Fnf_00086330();
};
class B_17980 {
  public:
    void* Fnf_000afe40(int);
};
class C_17980 {
  public:
    void Fnf_000afaf0();
};
extern A_17980* hulk_at_004dd6ec;

} // namespace fn_ff7d2848

// 0x00017870 CHapticEventAction::vfunc_3 (270 B): equivalent/0x00017870.cpp
// sym: ?vfunc_3@CHapticEventAction@@UAE_NHH@Z @f62604fc5dd2 @wc938e073428b
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// CHapticEventAction::vfunc_3 @ 0x00017870
bool CHapticEventAction::vfunc_3(hulk_intptr , hulk_intptr ) {
 if (!DAT_004dd700->gate->FUN_00099740()) {
  Controller_17870* controller=DAT_004dd6ec->FUN_00086330();
  Motors* motors=((Motors *)((owners::C_afe40 *)controller)->FUN_000afe40(0));
  for(int i=0;i<motors->count;++i) {
   float strength=(*(Event_17870 * *)&this->f_20)->strength0;
   float scale=controller->FUN_000afe60();
   motors->FUN_000af530(i,0,(strength*0.01f)*scale);
   strength=(*(Event_17870 * *)&this->f_20)->strength1;
   scale=controller->FUN_000afe70();
   motors->FUN_000af530(i,1,(strength*0.01f)*scale);
   Event_17870* e=(*(Event_17870 * *)&this->f_20);
   float finish=e->end();
   float begin=e->start();
   ((owners::Obj_af650 *)motors)->FUN_000af650(i, 0, finish-begin);
   e=(*(Event_17870 * *)&this->f_20);
   finish=e->end();
   begin=e->start();
   ((owners::Obj_af650 *)motors)->FUN_000af650(i, 1, finish-begin);
  }
 }
 return true;
}


// 0x00017980 CHapticEventAction::vfunc_4 (38 B): matches/0x00017980.cpp
// sym: ?vfunc_4@CHapticEventAction@@UAEXXZ
void CHapticEventAction::vfunc_4() {
    if (*((char*)(*(void * *)&this->f_20) + 0x1c)) {
        void* p = hulk_at_004dd6ec->Fnf_00086330();
        B_17980* b = (B_17980*)p;
        C_17980* c = (C_17980*)b->Fnf_000afe40(0);
        c->Fnf_000afaf0();
    }
}

