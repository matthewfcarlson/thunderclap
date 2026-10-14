// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CJumpAttackAction::vfunc_7 @ 0x00017270
struct Vec { float x,y,z; void FUN_0022be40(const Vec*); };
struct Mode { void FUN_000359c0(int); };
struct Actor { Mode* FUN_00059a30(); void FUN_00059a50(Vec*); };
struct Owner { Actor* FUN_000592a0(); };
struct Speed { char pad[0x28]; float value; };
struct Destination { char pad[0x18]; Vec position; };
struct CJumpAttackAction {
 char pad[0x1c]; Owner* owner; Speed* speed; Destination* destination; Vec velocity;
 bool vfunc_7(float dt);
};
bool CJumpAttackAction::vfunc_7(float dt) {
 if (!destination) return false;
 Actor* actor=owner->FUN_000592a0();
 actor->FUN_00059a30()->FUN_000359c0(3);
 Vec position; position.x=0; position.y=0; position.z=0;
 actor->FUN_00059a50(&position);
 double scale=(double)dt*speed->value;
 float y=(float)(velocity.y*scale);
 float z=(float)(velocity.z*scale);
 position.x=(float)(position.x+velocity.x*scale);
 position.y+=y; position.z+=z;
 destination->position.FUN_0022be40(&position);
 return true;
}