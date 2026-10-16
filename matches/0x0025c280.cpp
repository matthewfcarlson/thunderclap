#include "gen/audio.h"

bool audio::OmHalStream::vfunc_8(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    *out = this->f_1b4;
    int v = this->f_1b4;
    *(int*)((char*)this + 8) -= v;
    this->f_1b4 = 0;
    return true;
}
