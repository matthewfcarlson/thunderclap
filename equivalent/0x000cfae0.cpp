// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure3<HUDOverlay,int,const_char_*,const_char_*,float>::vfunc_2 @ 0x000cfae0
#include "gen/global.h"

struct HUDOverlay_cfae0 {
    int FUN_000cfae0(const char *, const char *, float);
};
struct Arguments {
    const char *first;
    const char *second;
    float third;
};

template <> void Closure3<HUDOverlay, int, const char *, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * args = (Arguments *)__p1; int * result = (int *)__p2;

    const char *first = args->first;
    const char *second = args->second;
    float third = args->third;
    int value = ((*(HUDOverlay_cfae0 * *)&this->f_20)->*(*(int (HUDOverlay_cfae0::**)(const char *, const char *, float))&this->f_1c))(first, second, third);
    if (result) *result = value;
}
