// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::FlyingDashAction::vfunc_5 @ 0x001345d0
struct Vec3_1345d0 { float x,y,z; };
struct Transform_1345d0 { void FUN_0022be40(const Vec3_1345d0*); };
struct Object { char pad[0x18]; Transform_1345d0 transform; };
struct Mode_1345d0 { void FUN_000359c0(int); };
struct Actor_1345d0 { Mode_1345d0* FUN_00059a30(); void FUN_00059a50(Vec3_1345d0*); };
struct Owner_1345d0 { Actor_1345d0* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct FlyingDashAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,float);
 char padding[0x1c]; Owner_1345d0* owner; Object* object; Vec3_1345d0 velocity;
};
bool FlyingDashAction::vfunc_5(int state,float dt) {
 if(state!=0) return true;
 if(!object) return false;
 Actor_1345d0* actor=owner->FUN_000592a0();
 actor->FUN_00059a30()->FUN_000359c0(3);
 Vec3_1345d0 position; position.x=0.0f; position.y=0.0f; position.z=0.0f;
 actor->FUN_00059a50(&position);
 volatile float dz=velocity.z*dt;
 position.x=position.x+velocity.x*dt;
 position.y=position.y+velocity.y*dt;
 position.z=position.z+dz;
 object->transform.FUN_0022be40(&position);
 return true;
}
}}
