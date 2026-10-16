#include "gen/pure3d.h"

void pure3d::MultiController::vfunc_6(float x, char update) {
    this->f_18 = x * this->f_20 + this->f_18;
    if (update == 1)
        vfunc_7();
}
