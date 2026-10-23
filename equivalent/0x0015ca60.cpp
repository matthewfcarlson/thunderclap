// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::HeliLocomotionAction::vfunc_3 @ 0x0015ca60
struct Controller_15ca60; struct Entity; struct Motion_15ca60; struct Clip;
struct Owner_15ca60 { Controller_15ca60* FUN_000592a0(); };
struct Controller_15ca60 { Entity* FUN_00059a30(); Motion_15ca60* FUN_00059a40(); };
struct Vector { float x,y,z; };
struct Entity { char pad[0x8c]; unsigned int state; float FUN_000354c0(); void FUN_00035660(Vector*); void FUN_00035980(int); };
struct Settings_15ca60 { char pad[0x8c]; float x,y,z; };
struct Label_15ca60 { void FUN_0027b040(const char*); };
struct Clip { virtual void vfunc_0(); unsigned int pad; Label_15ca60 label; Clip* FUN_002248f0(int); };
struct Motion_15ca60 { void FUN_00222890(Clip*,float,float,float,float,float,float); };
void* __cdecl FUN_00263ea0(unsigned int);
namespace hulkfight { namespace motion {
struct HeliLocomotionAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Settings_15ca60* settings; Owner_15ca60* owner; Clip* clip; float value; unsigned int state; Vector vector;
};
bool HeliLocomotionAction::vfunc_3(int,int) {
 Controller_15ca60* controller=owner->FUN_000592a0();
 Entity* entity=controller->FUN_00059a30();
 Motion_15ca60* motion=controller->FUN_00059a40();
 if (!motion) return false;
 float x=settings->x, y=settings->y, z=settings->z;
 Clip* created=(Clip*)FUN_00263ea0(0x70);
 if(created) created=created->FUN_002248f0(0);
 clip=created;
 created->label.FUN_0027b040("heliLocomotion");
 clip->vfunc_0();
 motion->FUN_00222890(clip,-1.0f,x,1.0f,y,z,-1.0f);
 value=entity->FUN_000354c0();
 state=entity->state;
 entity->FUN_00035660(&vector);
 entity->FUN_00035980(1);
 return true;
}
}}
