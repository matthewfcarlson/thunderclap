#include "gen/global.h"

void TextSelector::vfunc_21(int index, unsigned char value) {
    if (index >= 0 && index < this->f_1d58)
        ((char*)this)[index * 0x38 + 0x18c] = value;
}
