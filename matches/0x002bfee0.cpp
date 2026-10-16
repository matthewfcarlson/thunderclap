#include "gen/pure3d.h"

unsigned int pure3d::Image8::vfunc_9(int a, int b) {
    return (*(int (*)[256])&this->f_30)[(*(unsigned char * *)&this->f_24)[this->f_10 * b + a]];
}
