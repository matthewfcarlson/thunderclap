#include "gen/movie.h"

extern void __stdcall FUN_00366b40(int, int);

void movie::PlayerBink::vfunc_8() {
    if (this->f_18 == 3) {
        FUN_00366b40((*(int *)&this->f_1c), 0);
        this->f_18 = 4;
        return;
    }
    if (this->f_18 == 1)
        this->f_18 = 2;
}
