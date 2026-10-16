#include "gen/fight.h"

unsigned char fight::BufferStringReader::vfunc_5() {
    unsigned int p = this->f_14;
    if (p >= this->f_10)
        return 0;
    unsigned char c = (*(unsigned char * *)&this->f_08)[p];
    this->f_14 = p + 1;
    return c;
}
