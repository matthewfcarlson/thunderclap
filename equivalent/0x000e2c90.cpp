// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000e2c90 @ 0x000e2c90
#include "decls/address.h"
struct State_e2c90 { bool FUN_000b4f20(); bool FUN_000b8c90(); };
struct Manager_e2c90 { State_e2c90* FUN_00086280(); };
struct World { char pad[0x54]; Manager_e2c90* manager; };
struct Controller_e2c90 {
 virtual void slot0();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39(); virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47(); virtual void setMode(int);
};
struct Link_e2c90 { char pad[4]; Controller_e2c90* controller; };
struct Owner_e2c90 { char pad[8]; Link_e2c90* link; };
struct Entry_e2c90 { virtual void slot0(); virtual void finish(); virtual void slot2(); virtual void slot3(); virtual bool update(int, int, int, int); };
struct Target_e2c90 {
 char pad0[0x14]; Owner_e2c90* owner; char pad18[0x90]; int value; char padAC[0x6c]; Entry_e2c90* entries[10]; unsigned char enabled;
 void FUN_000e2c90(int mode,int arg2,int arg3);
};
void Target_e2c90::FUN_000e2c90(int mode,int arg2,int arg3) {
 if (enabled && (mode==0 || mode==1)) {
 State_e2c90* s=DAT_004dd700->manager->FUN_00086280();
 if(s->FUN_000b4f20() && s->FUN_000b8c90()) return;
 }
 if(enabled && mode==0) owner->link->controller->setMode(mode);
 for(int i=0;i<10;++i) {
 if(!entries[i]) break;
 if(entries[i]->update(mode,value,arg2,arg3)) entries[i]->finish();
 }
}
