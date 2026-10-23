// STATUS: equivalent (tools/equiv.py level 3: 2977 inputs, branch coverage 6/6)
// physics::SimStateArticulated::vfunc_7 @ 0x002fd520
#include "gen/physics.h"

struct Joint_2fd520 {
    char pad0[4];
    int f4, f8, fc, f10, f14, f18;
    unsigned char f1c;
    char pad1d[0x64 - 0x1d];
};

struct Chain_2fd520 {
    char pad0[8];
    int FUN_0030f450();
};

namespace physics {
}
void physics::SimStateArticulated::vfunc_7() {
    this->f_58 = 0;
    this->f_54 = 0;
    (*(int *)&this->f_50) = 0;
    this->f_64 = 0;
    this->f_60 = 0;
    this->f_5c = 0;
    this->f_80 = 0;
    if ((*(Chain_2fd520 * *)&this->f_88) != 0) {
        for (int i = 0; i < (*(Chain_2fd520 * *)&this->f_88)->FUN_0030f450(); i++) {
            Joint_2fd520 *j = &(*(Joint_2fd520 * *)&this->f_8c)[i];
            j->f1c = 1;
            j->fc = 0;
            j->f8 = 0;
            j->f4 = 0;
            j->f18 = 0;
            j->f14 = 0;
            j->f10 = 0;
        }
    }
}
