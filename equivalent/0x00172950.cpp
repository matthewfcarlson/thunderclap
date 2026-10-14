// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::SnapToGroundAction::vfunc_3 @ 0x00172950
struct Vec_172950 { float x,y,z; };
struct Actor_172950;
struct Entity { Actor_172950* FUN_00059a30(); void FUN_00059a50(Vec_172950*); };
struct Handle_172950 { Entity* FUN_000592a0(); };
struct Actor_172950 {
 char pad[0x1a39];
 unsigned char grounded;
 char pad2[2];
 Vec_172950 fallback;
 char pad3[0x18];
 Vec_172950 ground;
 void FUN_00035250(Vec_172950*);
 bool FUN_00038660(Vec_172950*, float, Vec_172950*, Vec_172950*, int, int, int, int, int);
};
namespace hulkfight { namespace motion {
struct SnapToGroundAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x1c]; Handle_172950* handle;
};
bool SnapToGroundAction::vfunc_3(int,int) {
 if(handle) {
 Entity* entity=handle->FUN_000592a0();
 if(entity) {
 Actor_172950* actor=entity->FUN_00059a30();
 if(actor) {
 if(actor->grounded) { actor->FUN_00035250(&actor->ground); return false; }
 Vec_172950 start; start.x=0;start.y=0;start.z=0;
 entity->FUN_00059a50(&start);
 start.y += 10.0f;
 Vec_172950 result, normal;
 if(actor->FUN_00038660(&start,10000.0f,&result,&normal,0,0,-1,0,0)) actor->FUN_00035250(&result);
 else actor->FUN_00035250(&actor->fallback);
 }
 }
 }
 return false;
}
}}
