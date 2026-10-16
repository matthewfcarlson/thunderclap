#include "gen/global.h"

void FEContainer::vfunc_21(int param) {
    if (param != 0 && this->f_850 < 0x80) {
        (*(int (*)[128])&this->f_4c)[this->f_850] = param;
        ++this->f_850;
    }
}
