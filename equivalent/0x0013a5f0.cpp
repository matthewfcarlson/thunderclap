// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 7/8, incomplete)
// hulkfight::motion::AnimationAction::vfunc_5 @ 0x0013a5f0
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct AnimationState;
struct AnimationResult {
    bool FUN_00222a00(unsigned int value);
};
struct AnimationState {
    AnimationResult* FUN_00059a40();
};
struct AnimationSource {
    AnimationState* FUN_000592a0();
};
namespace hulkfight { namespace motion {

}}
bool hulkfight::motion::AnimationAction::vfunc_5(hulk_intptr event, int unused) {
    if (event != 1) return true;
    AnimationState* state = (*(AnimationSource * *)&this->f_20)->FUN_000592a0();
    AnimationResult* result = state->FUN_00059a40();
    if (!result) return false;
    return !result->FUN_00222a00((*(unsigned int *)&this->f_24));
}
