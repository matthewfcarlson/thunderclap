// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 4/4)
// CMoveAction::vfunc_7 @ 0x00014d40
#include "decls/data/game/global.h"

struct Vec_14d40 { float x,y,z; void FUN_0022be40(const Vec_14d40*); };
struct Heading;
struct Heading { float FUN_000354c0(); };
struct Actor_14d40 { Heading* FUN_00059a30(); void FUN_00059a50(Vec_14d40*); };
struct Owner_14d40 { Actor_14d40* FUN_000592a0(); };
struct Motion_14d40 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); char pad[16]; float speed; float angle; };
struct Destination_14d40 { char pad[24]; Vec_14d40 position; };
void __cdecl FUN_00224d70(float,Vec_14d40*);
struct CMoveAction { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual bool vfunc_7(float); virtual void slot8(); char pad[24]; Owner_14d40* owner; Motion_14d40* motion; Destination_14d40* destination; };
bool CMoveAction::vfunc_7(float dt) {
 if (!destination) return false;
 Actor_14d40* actor=owner->FUN_000592a0();
 Heading* heading=actor->FUN_00059a30();
 float duration=motion->slot7();
 if (duration<=0.0f) return false;
 Vec_14d40 delta;
 delta.x=(*(float*)&DAT_0048e054); delta.y=(*(float*)((char*)&DAT_0048e054 + 4)); delta.z=(*(float*)((char*)&DAT_0048e054 + 8));
 double scale=((double)motion->speed/duration)*dt;
 delta.x=(float)(delta.x*scale); delta.y=(float)(delta.y*scale); delta.z=(float)(delta.z*scale);
 float angle=motion->angle;
 float turn=heading->FUN_000354c0();
 FUN_00224d70((float)((double)turn+angle),&delta);
 Vec_14d40 position; position.x=0;position.y=0;position.z=0;
 actor->FUN_00059a50(&position);
 delta.x=position.x+delta.x; delta.y=position.y+delta.y; delta.z=position.z+delta.z;
 destination->position.FUN_0022be40(&delta);
 return true;
}