#include "gen/core.h"

void core::Timer::vfunc_6(int x) {
    if (this->f_10) {
        vfunc_10();
        (*(int *)&this->f_0c) = x;
        vfunc_9();
    } else {
        (*(int *)&this->f_0c) = x;
    }
}
