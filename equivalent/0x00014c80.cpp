// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// CMoveAction::vfunc_6 @ 0x00014c80
struct Name_14c80 { void FUN_0027b040(const char*); };
struct Transform_14c80 { char data[48]; void FUN_0022be40(const Transform_14c80*); };
struct Move_14c80 { virtual void vfunc_0(); char pad[4]; Name_14c80 name; char pad2[8]; unsigned enabled; Transform_14c80 transform; Move_14c80* FUN_002248f0(int); };
struct Actor_14c80 { char pad[64]; Transform_14c80 transform; void FUN_00222890(Move_14c80*, float, unsigned, float, unsigned, unsigned, float); };
struct Context { Actor_14c80* FUN_00059a40(); };
struct Owner_14c80 { Context* FUN_000592a0(); };
struct Params { char pad[28]; unsigned x,y,z; };
extern Move_14c80* __cdecl FUN_00263ea0(unsigned);
struct CMoveAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); virtual void vfunc_7(); virtual void vfunc_8();
 char pad[24]; Owner_14c80* owner; Params* params; Move_14c80* move;
};
bool CMoveAction::vfunc_6(int) {
 Actor_14c80* actor = owner->FUN_000592a0()->FUN_00059a40();
 if (!actor) return false;
 unsigned y=params->y, z=params->z, x=params->x;
 Move_14c80* allocated=FUN_00263ea0(0x70);
 Move_14c80* created=allocated ? allocated->FUN_002248f0(0) : 0;
 move=created;
 created->name.FUN_0027b040("move");
 move->vfunc_0();
 move->transform.FUN_0022be40(&actor->transform);
 move->enabled=1;
 actor->FUN_00222890(move,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}