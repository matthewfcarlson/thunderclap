// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// CHapticEventAction::vfunc_3 @ 0x00017870
#include "compat/ptr.h"
#include "gen/global.h"
#include "decls/address.h"

struct Gate_17870 { bool FUN_00099740(); };
struct World { char pad[8]; Gate_17870* gate; };
struct Motors { char pad[16]; int count; void FUN_000af530(int index,int channel,float value); void FUN_000af650(int index,int channel,float value); };
struct Controller_17870 { Motors* FUN_000afe40(int); float FUN_000afe60(); float FUN_000afe70(); };
struct Singleton_4dd6ec { Controller_17870* FUN_00086330(); };
struct Event_17870 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual float start(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual float end();
 char pad[16]; float strength0; float strength1;
};

bool CHapticEventAction::vfunc_3(hulk_intptr , hulk_intptr ) {
 if (!DAT_004dd700->gate->FUN_00099740()) {
  Controller_17870* controller=DAT_004dd6ec->FUN_00086330();
  Motors* motors=controller->FUN_000afe40(0);
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
   motors->FUN_000af650(i,0,finish-begin);
   e=(*(Event_17870 * *)&this->f_20);
   finish=e->end();
   begin=e->start();
   motors->FUN_000af650(i,1,finish-begin);
  }
 }
 return true;
}
