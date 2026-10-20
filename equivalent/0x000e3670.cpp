// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// TextSelector::vfunc_6 @ 0x000e3670
#include "gen/global.h"

struct Receiver { void FUN_000f92f0(int, int, int); };

void TextSelector::vfunc_6(int __p0) { Receiver * receiver = (Receiver *)__p0;

    if (this->f_90 != 0 || this->f_94 != 0)
        receiver->FUN_000f92f0(this->f_90, this->f_94, (*(signed char *)&this->f_154));
}
