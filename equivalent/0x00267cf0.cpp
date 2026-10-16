// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 8/8)
// core::Timer::vfunc_10 @ 0x00267cf0
#include "gen/core.h"

namespace core {

struct TimerManager {
    char reserved[0x1c];
    unsigned int count;
    core::Timer **timers;
};

}
void core::Timer::vfunc_10() {
    if (this->f_10) {
        this->f_10 = 0;
        if ((*(TimerManager * *)&this->f_20)->count) {
            core::Timer **list = (*(TimerManager * *)&this->f_20)->timers;
            for (unsigned int i = 0; i < (*(TimerManager * *)&this->f_20)->count; ++i) {
                if (list[i] == this) {
                    list[i] = 0;
                    break;
                }
            }
        }
    }
}
