#include "gen/global.h"

void FEThingsBase::vfunc_31() {
    vfunc_48(1);
    --this->f_17f4;
    if (this->f_17f4 < 0)
        this->f_183c = 0;
    else
        this->f_183c = (*(int (*)[16])&this->f_17b4)[this->f_17f4];
    this->f_1830 = 2;
    this->f_1838 = 0;
    this->f_1834 = 0x3f800000;
}
