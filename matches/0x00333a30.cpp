#include "gen/movie.h"

bool movie::PlayerBink::vfunc_13(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    if ((*(void * *)&this->f_1c)) {
        out[1] = *(unsigned int*)(*(void * *)&this->f_1c);
        out[0] = *((unsigned int*)(*(void * *)&this->f_1c) + 1);
        return true;
    }
    return false;
}
