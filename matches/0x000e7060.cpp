#include "gen/global.h"

void FEThingsBase::vfunc_25(int param) {
    if (param != 0 && this->f_17b0 < 15) {
        int i = ++this->f_17b0;
        (*(int (*)[16])&this->f_1770)[i] = param;
    }
}
