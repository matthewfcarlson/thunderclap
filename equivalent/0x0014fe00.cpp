// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// hulkfight::motion::HitOrientToPushbackAction::vfunc_3 @ 0x0014fe00
struct ActorInfo { float FUN_000354c0(); };
struct PushbackAction;
struct Motion { void FUN_00222890(PushbackAction*, float, float, float, float, float, float); };
struct Actor { ActorInfo* FUN_00059a30(); Motion* FUN_00059a40(); };
struct Owner { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual int slot3(); Actor* FUN_000592a0(); };
struct HitData { char pad[0x18]; float x,y,z; };
struct Name { void FUN_0027b040(const char*); char bytes[12]; };
struct Parameter { void FUN_00221d20(float); };
struct PushbackAction { virtual void slot0(); char pad[4]; Name name; int mode; Parameter parameter; PushbackAction* FUN_002248f0(int); };
extern void* __cdecl FUN_00263ea0(unsigned int);
namespace hulkfight { namespace motion {
struct HitOrientToPushbackAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5(); char pad[0x18]; HitData* hit; Owner* owner; PushbackAction* action; };
bool HitOrientToPushbackAction::vfunc_3(int,int) {
 if (!owner) return false;
 Actor* actor=owner->FUN_000592a0();
 ActorInfo* info=actor->FUN_00059a30();
 Motion* motion=actor->FUN_00059a40();
 if (!motion || !owner->slot3()) return false;
 float x=hit->x, y=hit->y, z=hit->z;
 PushbackAction* p=(PushbackAction*)FUN_00263ea0(0x70);
 if(p) p=p->FUN_002248f0(0);
 action=p;
 p->name.FUN_0027b040("hitOrientToPushback");
 action->mode=2;
 action->slot0();
 float value=info->FUN_000354c0();
 action->parameter.FUN_00221d20(value);
 motion->FUN_00222890(action,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}
}}
