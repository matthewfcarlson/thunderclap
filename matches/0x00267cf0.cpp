#include "gen/core.h"

namespace core {

struct TimerManager {
    char reserved[0x1c];
    unsigned int count;
    core::Timer** timers;
};

} // namespace core
void core::Timer::vfunc_10() {
    if (this->f_10) {
        TimerManager* mgr = (*(TimerManager *volatile *)&this->f_20);
        this->f_10 = 0;
        unsigned int i = 0;
        if (mgr->count > 0) {
            core::Timer** list = mgr->timers;
            core::Timer** cur = list;
            do {
                if (*cur == this) {
                    list[i] = 0;
                    break;
                }
                ++i;
                ++cur;
            } while (i < (*(TimerManager *volatile *)&this->f_20)->count);
        }
    }
}
