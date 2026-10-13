// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CMoveAction::vfunc_7 @ 0x00014d40
struct Vec { float x,y,z; void FUN_0022be40(const Vec*); };
struct Heading;
// equiv-conv: FUN_000354c0 ecx stack
float __cdecl FUN_000354c0(Heading*,Vec*);
struct Actor { Heading* FUN_00059a30(); void FUN_00059a50(Vec*); };
struct Owner { Actor* FUN_000592a0(); };
struct Motion { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7(); char pad[16]; float speed; float angle; };
struct Destination { char pad[24]; Vec position; };
extern float DAT_0048e054, DAT_0048e058, DAT_0048e05c;
void __cdecl FUN_00224d70(float,Vec*);
struct CMoveAction { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual bool vfunc_7(float); virtual void slot8(); char pad[24]; Owner* owner; Motion* motion; Destination* destination; };
bool CMoveAction::vfunc_7(float dt) {
 if (!destination) return false;
 Actor* actor=owner->FUN_000592a0();
 Heading* heading=actor->FUN_00059a30();
 float duration=motion->slot7();
 if (duration<=0.0f) return false;
 Vec delta;
 delta.x=DAT_0048e054; delta.y=DAT_0048e058; delta.z=DAT_0048e05c;
 double scale=((double)motion->speed/duration)*dt;
 delta.x=(float)(delta.x*scale); delta.y=(float)(delta.y*scale); delta.z=(float)(delta.z*scale);
 float angle=motion->angle;
 float turn=FUN_000354c0(heading,&delta);
 FUN_00224d70((float)((double)turn+angle),&delta);
 Vec position; position.x=0;position.y=0;position.z=0;
 actor->FUN_00059a50(&position);
 delta.x=position.x+delta.x; delta.y=position.y+delta.y; delta.z=position.z+delta.z;
 destination->position.FUN_0022be40(&delta);
 return true;
}