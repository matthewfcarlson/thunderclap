#include "compat/ptr.h"
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042bf6c[];
extern "C" char DAT_004342e8[];
extern "C" char DAT_004342fc[];
extern "C" void* Allocate(void*, unsigned int);
extern "C" void Init();
extern "C" volatile unsigned int gStored;
extern "C" volatile void* gResult_3351a0;
struct Callback_3351a0 {
    hulk_uintptr vtable;
    unsigned int arg;
    hulk_uintptr subVtable;
    unsigned int field;
};
void CreateCallback(hulk_uintptr arg) {
    gStored = arg;
    Callback_3351a0* p = (Callback_3351a0*)Allocate((void*)arg, 0x10);
    if (p) {
        p->vtable = ((hulk_intptr)DAT_0042afa8);
        p->arg = gStored;
        Init();
        *(volatile hulk_uintptr*)&p->subVtable = ((hulk_intptr)DAT_0042bf6c);
        p->vtable = ((hulk_intptr)DAT_004342fc);
        p->subVtable = ((hulk_intptr)DAT_004342e8);
        p->field = 0;
        gResult_3351a0 = p;
    } else
        gResult_3351a0 = 0;
}