#include "gen/global.h"

bool CHand2HandAgent::vfunc_18(float limit) {
    float d = this->f_8c - this->f_a8;
    union {
        float f;
        unsigned int i;
    } u;
    u.f = d;
    u.i &= 0x7fffffff;
    return u.f < limit;
}
