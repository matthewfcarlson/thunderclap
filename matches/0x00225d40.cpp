#include "gen/choreo2.h"

extern float __stdcall GetValue(int);

void choreo2::AnimationDriver::vfunc_9(int x) {
    this->f_23c = GetValue(x);
}
