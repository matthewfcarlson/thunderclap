#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/movie.h"
// data: gResult_3351a0 = DAT_00555ba8, gStored = DAT_004cdbb0

#include "compat/ptr.h"
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042bf6c[];
extern "C" char DAT_004342e8[];
extern "C" char DAT_004342fc[];
extern "C" void* Allocate(void*, unsigned int);
extern "C" void Init();
struct Callback_3351a0 {
    hulk_uintptr vtable;
    unsigned int arg;
    hulk_uintptr subVtable;
    unsigned int field;
};
void CreateCallback(hulk_uintptr arg) {
    (*(volatile unsigned int*)&DAT_004cdbb0) = arg;
    Callback_3351a0* p = (Callback_3351a0*)Allocate((void*)arg, 0x10);
    if (p) {
        p->vtable = ((hulk_intptr)DAT_0042afa8);
        p->arg = (*(volatile unsigned int*)&DAT_004cdbb0);
        Init();
        *(volatile hulk_uintptr*)&p->subVtable = ((hulk_intptr)DAT_0042bf6c);
        p->vtable = ((hulk_intptr)DAT_004342fc);
        p->subVtable = ((hulk_intptr)DAT_004342e8);
        p->field = 0;
        (*(volatile void**)&DAT_00555ba8) = p;
    } else
        (*(volatile void**)&DAT_00555ba8) = 0;
}