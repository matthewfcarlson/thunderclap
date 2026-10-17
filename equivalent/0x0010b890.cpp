// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// hulkfight::ai::FaceMotionAction::vfunc_5 @ 0x0010b890
struct MotionState {
    char pad[0x2064];
    volatile unsigned int positionX, positionY, positionZ;
    char gap[4];
    volatile unsigned int previousX, previousY, previousZ;
};
struct MotionOwner { MotionState* FUN_00059a30(); };
struct MotionSource { MotionOwner* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct FaceMotionAction {
    char pad[0x20];
    MotionSource* source;
    int vfunc_5(int mode, int unused);
};
int FaceMotionAction::vfunc_5(int mode, int unused) {
    if (mode) return (mode & ~255) | 1;
    if (!source) return 0;
    MotionOwner* owner = source->FUN_000592a0();
    MotionState* state = owner->FUN_00059a30();
    state->previousX = state->positionX;
    state->previousY = state->positionY;
    state->previousZ = state->positionZ;
    return (((unsigned int)state + 0x1f58) & ~255U) | 1;
}
}}
