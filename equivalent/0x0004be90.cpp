// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CCollisionDirectionCondition::vfunc_7 @ 0x0004be90
struct Actor { float FUN_000354c0(); };
struct Context2 { Actor* FUN_00059a30(); };
struct Collision { char pad[0x18]; float x; float y; float z; };
struct Context { virtual void v0(); virtual void v1(); virtual void v2(); virtual Collision* v3(); Context2* FUN_000592a0(); };
float __cdecl FUN_00224ea0(float,float);
float __cdecl FUN_00224fc0(float,float);
struct CCollisionDirectionCondition {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual bool vfunc_7(Context*);
 char pad[8]; float offset; float range;
};
bool CCollisionDirectionCondition::vfunc_7(Context* context) {
 Actor* actor = context->FUN_000592a0()->FUN_00059a30();
 Collision* collision = context->v3();
 if (!collision) return false;
 actor->FUN_000354c0();
 float direction = FUN_00224ea0(collision->x,collision->z);
 float heading = actor->FUN_000354c0() + offset;
 float delta = FUN_00224fc0(direction,heading);
 union { float f; unsigned int u; } absolute;
 absolute.f=delta; absolute.u &= 0x7fffffff;
 return range*0.5f > absolute.f;
}