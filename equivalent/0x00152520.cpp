// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// hulkfight::motion::HitOrientToPushbackAction::vfunc_5 @ 0x00152520
struct Vec { float x,y,z; };
struct Rotation { void FUN_00221d20(float); };
struct PushObject { char pad[0x18]; Rotation rotation; };
struct Settings { char pad[0x14]; float rate; };
struct Transform { char pad[0x28]; Vec direction; };
struct Motion { float FUN_000354c0(); };
struct Intermediate { Motion* FUN_00059a30(); };
struct Actor { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Transform* slot3(); Intermediate* FUN_000592a0(); };
extern float __cdecl FUN_00224f10(Vec*);
extern float __cdecl FUN_00224fc0(float,float);
namespace hulkfight { namespace motion {
struct HitOrientToPushbackAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int,float);
 char pad[0x18]; Settings* settings; Actor* actor; PushObject* push;
};
bool HitOrientToPushbackAction::vfunc_5(int flag,float dt) {
 if(flag) return true;
 if(!push) return false;
 Motion* m=actor->FUN_000592a0()->FUN_00059a30();
 Transform* t=actor->slot3();
 if(!t) return false;
 float current=m->FUN_000354c0();
 float target=FUN_00224f10(&t->direction);
 float rate=settings->rate;
 if(!(rate<=0.0f)) {
 float diff=FUN_00224fc0(current,target);
 float step=rate*dt;
 union { float f; unsigned int u; } mag;
 mag.f=diff; mag.u &= 0x7fffffff;
 if(!(mag.f<=step)) {
 if(diff<0.0f) current=current-step; else current=current+step;
 } else current=target;
 } else current=target;
 push->rotation.FUN_00221d20(current);
 return true;
}
}}
