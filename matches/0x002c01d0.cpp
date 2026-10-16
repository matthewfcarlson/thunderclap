#include "gen/pure3d.h"

void pure3d::Image32::vfunc_11(unsigned int value) {
    unsigned int* p = (*(unsigned int * *)&this->f_24);
    int count = this->f_14 * this->f_10;
    int i = 0;
    if (count > 0) {
        do {
            *p++ = value;
            ++i;
            count = this->f_14 * this->f_10;
        } while (i < count);
    }
}
