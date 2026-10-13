// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::MoveJointAction::vfunc_3 @ 0x001763c0
struct Vec { unsigned x,y,z; };
struct Matrix { char data[64]; void FUN_0022c2b0(Vec*,Vec*); };
struct Skeleton { unsigned FUN_0027b200(unsigned,unsigned); };
struct Pose { char pad[8]; Skeleton* skeleton; char pad2[16]; Matrix* matrices; };
struct Actor { char pad[0x120]; Pose* pose; void FUN_000373e0(int); };
struct Intermediate { Actor* FUN_00059a30(); };
struct Owner { Intermediate* FUN_000592a0(); };
struct Ref { virtual void vfunc_0(); virtual void vfunc_1(); };
Ref* __cdecl FUN_001817d0(Actor*,unsigned);
struct Settings { char pad[0x14]; unsigned selector; unsigned name1a,name1b,name2a,name2b; Vec position; char pad2[0x14]; unsigned value; };
namespace hulkfight { namespace motion {
struct MoveJointAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned,unsigned); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Settings* settings; Owner* owner; Ref* reference; char pad2[4]; Vec position; unsigned joint1,joint2; char pad3[0x10]; unsigned char active; char pad4[3]; unsigned value;
};
bool MoveJointAction::vfunc_3(unsigned,unsigned) {
 Actor* actor=owner->FUN_000592a0()->FUN_00059a30();
 Pose* pose=actor->pose;
 Skeleton* skeleton=pose->skeleton;
 unsigned a=settings->name1a,b=settings->name1b;
 if(a|b) { joint1=skeleton->FUN_0027b200(a,b); if(joint1==0xffff) joint1=0; }
 a=settings->name2a; b=settings->name2b;
 if(a|b) { joint2=skeleton->FUN_0027b200(a,b); if(joint2==0xffff) joint2=0; }
 Settings* config=settings;
 active=1; value=config->value;
 unsigned index=joint2;
 Matrix* matrices=pose->matrices;
 unsigned x=config->position.x,y=config->position.y,z=config->position.z;
 position.x=x; position.y=y; position.z=z;
 matrices[index].FUN_0022c2b0(&position,&position);
 Ref* next=FUN_001817d0(actor,settings->selector);
 if(next) next->vfunc_0();
 if(reference) reference->vfunc_1();
 reference=next;
 actor->FUN_000373e0(0);
 return true;
}
}}
