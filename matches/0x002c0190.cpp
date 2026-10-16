#include "gen/pure3d.h"

unsigned int pure3d::Image32::vfunc_9(int x, int y) {
    return (*(unsigned int * *)&this->f_24)[this->f_10 * y + x];
}
