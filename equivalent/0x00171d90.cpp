// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::motion::TeleportToLocatorAction::vfunc_5 @ 0x00171d90
#include "decls/address.h"
struct Vec3_171d90 { float x,y,z; };
struct Actor_171d90 { void FUN_0003f400(Vec3_171d90*); };
struct Intermediate_171d90 { Actor_171d90* FUN_00059a30(); };
struct Source_171d90 { Intermediate_171d90* FUN_000592a0(); };
struct Locator {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(Vec3_171d90*);
};
struct Manager_171d90 { Locator* FUN_001fc8c0(unsigned int,unsigned int); };
struct World { char pad[0x28]; Manager_171d90* manager; };
struct Offset_171d90 { char pad[0x14]; Vec3_171d90 displacement; };
namespace hulkfight { namespace motion {
struct TeleportToLocatorAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,int);
 char pad[0x18]; Offset_171d90* offset; Source_171d90* source; unsigned int unused; unsigned int key1,key2;
};
bool TeleportToLocatorAction::vfunc_5(int flag,int) {
 if(flag) return true;
 if(!source) return false;
 Intermediate_171d90* intermediate=source->FUN_000592a0();
 Actor_171d90* actor=intermediate->FUN_00059a30();
 Locator* locator=DAT_004dd700->manager->FUN_001fc8c0(key1,key2);
 if(!locator) return false;
 Vec3_171d90 position;
 locator->slot8(&position);
 Vec3_171d90 delta=offset->displacement;
 position.x=delta.x+position.x;
 position.y=delta.y+position.y;
 position.z=delta.z+position.z;
 actor->FUN_0003f400(&position);
 return true;
}
} }
