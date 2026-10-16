#include "gen/global.h"

int strncmp(const char*, const char*, unsigned int);

bool FEDoAction::vfunc_4(int a, int b, int c, int d) {
    if (a == this->f_04 && this->f_08 == c && this->f_0c == d) {
        if ((*(char (*)[32])&this->f_14)[0] == 0)
            return true;
        char* p = (char*)(b + 0x1734);
        if (p != 0 && strncmp(p, (*(char (*)[32])&this->f_14), 0x20) == 0)
            return true;
    }
    return false;
}
