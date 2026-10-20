// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// hulkfight::ai::FaceMotionAction::vfunc_5 @ 0x0010b890
#include "gen/hulkfight.h"

struct MotionState {
    char pad[0x2064];
    volatile unsigned int positionX, positionY, positionZ;
    char gap[4];
    volatile unsigned int previousX, previousY, previousZ;
};
struct MotionOwner { MotionState* FUN_00059a30(); };
struct MotionSource { MotionOwner* FUN_000592a0(); };
namespace hulkfight { namespace ai {

}}
bool hulkfight::ai::FaceMotionAction::vfunc_5(int mode, int unused) {
    if (mode) return (bool)((mode & ~255) | 1);
    if (!(*(MotionSource * *)&this->f_20)) return (bool)(0);
    MotionOwner* owner = (*(MotionSource * *)&this->f_20)->FUN_000592a0();
    MotionState* state = owner->FUN_00059a30();
    state->previousX = state->positionX;
    state->previousY = state->positionY;
    state->previousZ = state->positionZ;
    return (bool)((((unsigned int)state + 0x1f58) & ~255U) | 1);
}
