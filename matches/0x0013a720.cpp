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
struct AnimationLinkedAction {
    char pad[0x20];
    MotionSource* source;
    void* animation;
    bool vfunc_5(int event, int other);
};
bool AnimationLinkedAction::vfunc_5(int event, int other) {
    if (event == 1) {
        MotionInstance* instance = source->FUN_000592a0()->FUN_00059a40();
        bool result;
        if (!instance)
            result = true;
        else
            result = instance->FUN_00222a00(animation);
        return !result;
    }
    return true;
}
} // namespace motion
} // namespace hulkfight