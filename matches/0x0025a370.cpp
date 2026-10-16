#include "gen/audio.h"

extern "C" bool FUN_0024f010(void*, void*);
extern "C" bool FUN_0025ac10(void*, void*);
extern "C" bool FUN_0025aa80(void*, void*);

int audio::MixBuss::vfunc_1(void* __p0) { void * p = (void *)__p0;

    if (FUN_0024f010(p, &this->f_14) && FUN_0025ac10(p, &this->f_18) && FUN_0025ac10(p, &this->f_1c) && FUN_0025ac10(p, &this->f_20) &&
        FUN_0025ac10(p, &this->f_24) && FUN_0025aa80(p, &this->f_28))
        return 1;
    return 0;
}
