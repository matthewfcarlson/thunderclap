// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CMoveAddAction::vfunc_7 @ 0x00014e90
struct Vec { float x,y,z; };
struct Actor { float FUN_000354c0(); void FUN_00035720(Vec*); };
struct HandleResult { Actor* FUN_00059a30(); };
struct Handle { HandleResult* FUN_000592a0(); };
struct Move {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual float slot7();
 char pad[0x10]; float distance; float angle;
};
extern Vec DAT_0048e054;
void __cdecl FUN_00224d70(float, Vec*);
struct CMoveAddAction {
 char pad[0x1c]; Handle* handle; Move* move;
 bool vfunc_7(float dt);
};
bool CMoveAddAction::vfunc_7(float dt) {
 Actor* actor=handle->FUN_000592a0()->FUN_00059a30();
 float duration=move->slot7();
 if(duration<=0.0f) return false;
 Vec v=DAT_0048e054;
 Move* m=move;
 double factor=(double)m->distance/duration*dt;
 v.x=(float)(v.x*factor); v.y=(float)(v.y*factor); v.z=(float)(v.z*factor);
 float angle=m->angle;
 float heading=actor->FUN_000354c0();
 FUN_00224d70(heading+angle,&v);
 actor->FUN_00035720(&v);
 return true;
}