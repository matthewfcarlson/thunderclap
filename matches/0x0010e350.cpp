#include "compat/ptr.h"
#include "gen/hulkfight.h"

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

} // namespace ai
} // namespace hulkfight
bool hulkfight::ai::SemaphoreClearAction::vfunc_5(hulk_intptr , int ) {
    if (!(*(SemaphoreSource * *)&this->f_20))
        return false;
    if ((*(SemaphoreData * *)&this->f_1c)->enabled) {
        ClearTarget* target = (*(SemaphoreSource * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
        if ((*(SemaphoreData * *)&this->f_1c)->clearDirectly) {
            target->FUN_00037000();
            return true;
        }
        target->FUN_00037040(&(*(SemaphoreData * *)&this->f_1c)->value, 0, 1);
    }
    return true;
}
