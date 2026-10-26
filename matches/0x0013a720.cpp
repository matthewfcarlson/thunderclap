#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct MotionInstance {
    bool FUN_00222a00(void*);
};
struct MotionOwner {
    MotionInstance* FUN_00059a40();
};
struct MotionSource {
    MotionOwner* FUN_000592a0();
};
namespace hulkfight {
namespace motion {

} // namespace motion
} // namespace hulkfight
bool hulkfight::motion::AnimationLinkedAction::vfunc_5(hulk_intptr event, int other) {
    if (event == 1) {
        MotionInstance* instance = (*(MotionSource * *)&this->f_20)->FUN_000592a0()->FUN_00059a40();
        bool result;
        if (!instance)
            result = true;
        else
            result = instance->FUN_00222a00((*(void * *)&this->f_24));
        return !result;
    }
    return true;
}
