#include "gen/audio.h"

bool audio::HalRsdFileStream::vfunc_8(void* __p0) { int * out = (int *)__p0;

    if ((*(int *)&this->f_44) == 5)
        return false;
    *out = (*(int *)&this->f_3c);
    (*(int *)&this->f_44) = 4;
    return true;
}
