#include "gen/choreo2.h"

extern float __cdecl FUN_0022aaa0(float, float);

void choreo2::LocomotionStrafeDriver::vfunc_14(float param) {
    unsigned int i = 0;
    if (this->f_30 > 0) {
        char* p = (char*)this + 0x238;
        do {
            *(float*)p = FUN_0022aaa0(param, *(float*)(p - 0x204));
            ++i;
            p += 0x208;
        } while (i < this->f_30);
    }
}
