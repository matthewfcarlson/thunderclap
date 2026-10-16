#include "gen/pure3d.h"

void pure3d::Image32::vfunc_10(int x, int y, int value) {
    (*(int * *)&this->f_24)[this->f_10 * y + x] = value;
}
