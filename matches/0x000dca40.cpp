#include "gen/global.h"
#include "decls/data/game/global.h"
// data: alphabet = DAT_004a0d38


bool FETextInput::FUN_000dca40() {
    int i = 0;
    if (this->f_150 > 0) {
        do {
            int value = (*(int * *)&this->f_16c)[i];
            if (value >= 0)
                (*(char * *)&this->f_158)[i] = ((const char*)&DAT_004a0d38)[value];
            else
                (*(char * *)&this->f_158)[i] = 0;
            ++i;
        } while (i < this->f_150);
    }
    (*(char * *)&this->f_158)[this->f_150] = 0;
    return true;
}
