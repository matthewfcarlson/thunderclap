#include "gen/core.h"

extern void __stdcall XInputClose(int);

void core::ControllerXBox::vfunc_21(int p) {
    if (this->f_08)
        XInputClose(this->f_08);
    this->f_08 = p;
}
