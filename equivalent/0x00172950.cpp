// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::SnapToGroundAction::vfunc_3 @ 0x00172950
struct Vec { float x,y,z; };
struct Actor;
struct Entity { Actor* FUN_00059a30(); void FUN_00059a50(Vec*); };
struct Handle { Entity* FUN_000592a0(); };
struct Actor {
 char pad[0x1a39];
 unsigned char grounded;
 char pad2[2];
 Vec fallback;
 char pad3[0x18];
 Vec ground;
 void FUN_00035250(Vec*);
 bool FUN_00038660(Vec*, float, Vec*, Vec*, int, int, int, int, int);
};
namespace hulkfight { namespace motion {
struct SnapToGroundAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x1c]; Handle* handle;
};
bool SnapToGroundAction::vfunc_3(int,int) {
 if(handle) {
 Entity* entity=handle->FUN_000592a0();
 if(entity) {
 Actor* actor=entity->FUN_00059a30();
 if(actor) {
 if(actor->grounded) { actor->FUN_00035250(&actor->ground); return false; }
 Vec start; start.x=0;start.y=0;start.z=0;
 entity->FUN_00059a50(&start);
 start.y += 10.0f;
 Vec result, normal;
 if(actor->FUN_00038660(&start,10000.0f,&result,&normal,0,0,-1,0,0)) actor->FUN_00035250(&result);
 else actor->FUN_00035250(&actor->fallback);
 }
 }
 }
 return false;
}
}}
