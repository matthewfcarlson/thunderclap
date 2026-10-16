#include "gen/pure3d.h"

void pure3d::Image8::vfunc_19(int x, int y, unsigned char value) {
    (*(unsigned char * *)&this->f_24)[this->f_10 * y + x] = value;
}
