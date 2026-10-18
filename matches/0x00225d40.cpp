#include "gen/choreo2.h"

struct This_GetValue {
    float GetValue(int);
};

void choreo2::AnimationDriver::vfunc_9(int x) {
    this->f_23c = ((This_GetValue*)this)->GetValue(x);
}
