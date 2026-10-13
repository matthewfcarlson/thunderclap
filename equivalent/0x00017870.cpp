// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// CHapticEventAction::vfunc_3 @ 0x00017870
struct Gate { bool FUN_00099740(); };
struct GlobalGate { char pad[8]; Gate* gate; };
extern GlobalGate* DAT_004dd700;
struct Motors { char pad[16]; int count; void FUN_000af530(int index,int channel,float value); void FUN_000af650(int index,int channel,float value); };
struct Controller { Motors* FUN_000afe40(int); float FUN_000afe60(); float FUN_000afe70(); };
struct Manager { Controller* FUN_00086330(); };
extern Manager* DAT_004dd6ec;
struct Event {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual float start(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual float end();
 char pad[16]; float strength0; float strength1;
};
struct CHapticEventAction {
 char pad[32]; Event* event;
 bool vfunc_3(int,int);
};
bool CHapticEventAction::vfunc_3(int,int) {
 if (!DAT_004dd700->gate->FUN_00099740()) {
  Controller* controller=DAT_004dd6ec->FUN_00086330();
  Motors* motors=controller->FUN_000afe40(0);
  for(int i=0;i<motors->count;++i) {
   float strength=event->strength0;
   float scale=controller->FUN_000afe60();
   motors->FUN_000af530(i,0,(strength*0.01f)*scale);
   strength=event->strength1;
   scale=controller->FUN_000afe70();
   motors->FUN_000af530(i,1,(strength*0.01f)*scale);
   Event* e=event;
   float finish=e->end();
   float begin=e->start();
   motors->FUN_000af650(i,0,finish-begin);
   e=event;
   finish=e->end();
   begin=e->start();
   motors->FUN_000af650(i,1,finish-begin);
  }
 }
 return true;
}
