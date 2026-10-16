#include "gen/movie.h"

void __stdcall ReleaseHandle(void*);

void movie::PlayerBink::vfunc_7() {
    if (this->f_18) {
        ReleaseHandle((*(void * *)&this->f_1c));
        (*(void * *)&this->f_1c) = 0;
        this->f_18 = 0;
    }
}
