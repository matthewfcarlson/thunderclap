#include "gen/physics.h"

void physics::SimState::vfunc_3(char param) {
    char* x = (char*)(*(void * *)&this->f_74);
    if (x) {
        x[0x68] = param;
        if (param)
            *(char*)((char*)*(void**)(x + 0x20) + 0x19) = 0;
    }
}
