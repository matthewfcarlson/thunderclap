// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// CJumpAttackAction::vfunc_7 @ 0x00017270
struct Vec_17270 { float x,y,z; void FUN_0022be40(const Vec_17270*); };
struct Mode_17270 { void FUN_000359c0(int); };
struct Actor_17270 { Mode_17270* FUN_00059a30(); void FUN_00059a50(Vec_17270*); };
struct Owner_17270 { Actor_17270* FUN_000592a0(); };
struct Speed_17270 { char pad[0x28]; float value; };
struct Destination_17270 { char pad[0x18]; Vec_17270 position; };
struct CJumpAttackAction {
 char pad[0x1c]; Owner_17270* owner; Speed_17270* speed; Destination_17270* destination; Vec_17270 velocity;
 bool vfunc_7(float dt);
};
bool CJumpAttackAction::vfunc_7(float dt) {
 if (!destination) return false;
 Actor_17270* actor=owner->FUN_000592a0();
 actor->FUN_00059a30()->FUN_000359c0(3);
 Vec_17270 position; position.x=0; position.y=0; position.z=0;
 actor->FUN_00059a50(&position);
 double scale=(double)dt*speed->value;
 volatile float y=(float)(velocity.y*scale); // rounded copies in the original's velocity temporary
 volatile float z=(float)(velocity.z*scale);
 position.x=(float)(position.x+velocity.x*scale);
 position.y+=y; position.z+=z;
 destination->position.FUN_0022be40(&position);
 return true;
}