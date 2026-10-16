#include "gen/core.h"

void thunk_FUN_00270a50();
void FUN_0026d6d0(int);

void core::CementLibrary::vfunc_4() {
    while (this->f_20 == 0) {
        thunk_FUN_00270a50();
        FUN_0026d6d0(0);
    }
}
