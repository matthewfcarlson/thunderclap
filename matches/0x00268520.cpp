#include "gen/core.h"

#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042b14c[];
extern "C" void __stdcall XInputClose(void*);

void core::ControllerXBox::FUN_00268520() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b14c);
    if ((*(void * *)&this->f_08))
        XInputClose((*(void * *)&this->f_08));
    unsigned long* q = (unsigned long*)((char*)this + 0x448);
    int n = 2;
    do {
        q -= 4;
        n--;
        *(hulk_uintptr*)q = ((hulk_intptr)DAT_003f6098);
    } while (n);
    q = (unsigned long*)((char*)this + 0x428);
    n = 0x14;
    do {
        q -= 0xd;
        n--;
        *(hulk_uintptr*)q = ((hulk_intptr)DAT_003f6098);
    } while (n);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f6098);
}
