#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

struct SemaphoreData {
    char pad[0x18];
    int value;
    char pad2[4];
    char enabled;
    char clearDirectly;
};
struct ClearTarget {
    void FUN_00037000();
};
struct SemaphoreManager {
    ClearTarget* FUN_00059a30();
};
struct SemaphoreSource {
};
namespace hulkfight {
namespace ai {

} // namespace ai
} // namespace hulkfight
bool hulkfight::ai::SemaphoreClearAction::vfunc_5(hulk_intptr , int ) {
    if (!(*(SemaphoreSource * *)&this->f_20))
        return false;
    if ((*(SemaphoreData * *)&this->f_1c)->enabled) {
        ClearTarget* target = ((SemaphoreManager *)((owners::Object_592a0 *)((*(SemaphoreSource * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
        if ((*(SemaphoreData * *)&this->f_1c)->clearDirectly) {
            target->FUN_00037000();
            return true;
        }
        ((owners::C_37040 *)target)->FUN_00037040((hulk_intptr)(&(*(SemaphoreData * *)&this->f_1c)->value), 0, 1);
    }
    return true;
}
