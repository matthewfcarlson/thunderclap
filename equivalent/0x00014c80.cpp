// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// CMoveAction::vfunc_6 @ 0x00014c80
struct Name { void FUN_0027b040(const char*); };
struct Transform { char data[48]; void FUN_0022be40(const Transform*); };
struct Move { virtual void vfunc_0(); char pad[4]; Name name; char pad2[8]; unsigned enabled; Transform transform; Move* FUN_002248f0(int); };
struct Actor { char pad[64]; Transform transform; void FUN_00222890(Move*, float, unsigned, float, unsigned, unsigned, float); };
struct Context { Actor* FUN_00059a40(); };
struct Owner { Context* FUN_000592a0(); };
struct Params { char pad[28]; unsigned x,y,z; };
extern Move* __cdecl FUN_00263ea0(unsigned);
struct CMoveAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); virtual void vfunc_7(); virtual void vfunc_8();
 char pad[24]; Owner* owner; Params* params; Move* move;
};
bool CMoveAction::vfunc_6(int) {
 Actor* actor = owner->FUN_000592a0()->FUN_00059a40();
 if (!actor) return false;
 unsigned y=params->y, z=params->z, x=params->x;
 Move* allocated=FUN_00263ea0(0x70);
 Move* created=allocated ? allocated->FUN_002248f0(0) : 0;
 move=created;
 created->name.FUN_0027b040("move");
 move->vfunc_0();
 move->transform.FUN_0022be40(&actor->transform);
 move->enabled=1;
 actor->FUN_00222890(move,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}