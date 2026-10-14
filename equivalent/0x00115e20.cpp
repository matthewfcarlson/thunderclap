// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// hulkfight::ai::MotionFacingAction::vfunc_5 @ 0x00115e20
struct Vector { float x,y,z; float FUN_0022d110(); };
struct Actor { char pad[0x2064]; Vector facing; float rate; };
struct HandleResult { Actor* FUN_00059a30(); };
struct Handle { HandleResult* FUN_000592a0(); };
struct Settings { char pad[0x14]; float angle; Vector direction; float rate; };
// equiv-conv: FUN_000354c0 ecx stack
float __cdecl FUN_000354c0(Actor*, Vector*);
void __cdecl FUN_00224d70(float, Vector*);
namespace hulkfight { namespace ai {
struct MotionFacingAction {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(int, int);
char pad[0x18]; Settings* settings; Handle* handle;
};
bool MotionFacingAction::vfunc_5(int phase, int unused) {
if (phase != 0) return true;
if (!handle) return false;
Actor* actor = handle->FUN_000592a0()->FUN_00059a30();
Vector direction = settings->direction;
float angle = settings->angle;
FUN_00224d70(FUN_000354c0(actor, &direction) + angle, &direction);
direction.FUN_0022d110();
actor->facing = direction;
actor->rate = settings->rate;
return true;
}
}}
