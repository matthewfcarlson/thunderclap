#include "gen/movie.h"

extern void __stdcall FUN_00366b40(int, int);

void movie::PlayerBink::vfunc_9() {
    if (this->f_18 == 4) {
        FUN_00366b40((*(int *)&this->f_1c), 1);
        this->f_18 = 3;
        return;
    }
    if (this->f_18 == 2)
        this->f_18 = 1;
}
