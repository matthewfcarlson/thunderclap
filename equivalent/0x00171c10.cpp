// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// hulkfight::motion::DriftToHulkAction::vfunc_3 @ 0x00171c10
struct HulkState { char pad[0x2140]; unsigned char active; };
struct Actor { HulkState* FUN_00059a30(); };
struct Handle { Actor* FUN_000592a0(); };
struct Motion { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual float vfunc_7(); };
namespace hulkfight { namespace motion {
struct DriftToHulkAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int a, int b); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; Motion* motion; Handle* handle; char rest[0xc]; float speed; unsigned char previous;
};
bool DriftToHulkAction::vfunc_3(int a, int b) {
 Actor* actor = handle->FUN_000592a0();
 if (!actor) return false;
 HulkState* state = actor->FUN_00059a30();
 if (!state) return false;
 previous = state->active;
 state->active = 1;
 float value = motion->vfunc_7();
 speed = value;
 return !(value <= 0.0f);
}
}}