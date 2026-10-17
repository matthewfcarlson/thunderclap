// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 7/8, incomplete)
// hulkfight::motion::AnimationLinkedAction::vfunc_5 @ 0x0013a720
struct MotionInstance { bool FUN_00222a00(void *); };
struct MotionOwner { MotionInstance * FUN_00059a40(); };
struct MotionSource { MotionOwner * FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct AnimationLinkedAction {
    char pad[0x20];
    MotionSource *source;
    void *animation;
    bool vfunc_5(int event, int other);
};
bool AnimationLinkedAction::vfunc_5(int event, int other)
{
    if (event != 1) return true;
    MotionInstance *instance = source->FUN_000592a0()->FUN_00059a40();
    if (!instance) return false;
    return !instance->FUN_00222a00(animation);
}
} }