struct SemaphoreData {
    char pad[0x18];
    int value;
    char pad2[4];
    char enabled;
    char clearDirectly;
};
struct ClearTarget {
    void FUN_00037000();
    void FUN_00037040(int* value, int zero, int one);
};
struct SemaphoreManager {
    ClearTarget* FUN_00059a30();
};
struct SemaphoreSource {
    SemaphoreManager* FUN_000592a0();
};
namespace hulkfight {
namespace ai {
struct SemaphoreClearAction {
    char pad[0x1c];
    SemaphoreData* data;
    SemaphoreSource* source;
    bool vfunc_5(int, int);
};
bool SemaphoreClearAction::vfunc_5(int, int) {
    if (!source)
        return false;
    if (data->enabled) {
        ClearTarget* target = source->FUN_000592a0()->FUN_00059a30();
        if (data->clearDirectly) {
            target->FUN_00037000();
            return true;
        }
        target->FUN_00037040(&data->value, 0, 1);
    }
    return true;
}
} // namespace ai
} // namespace hulkfight
