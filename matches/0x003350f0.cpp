#include "compat/ptr.h"
#include "decls/data/engine/core.h"

extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042bf6c[];
extern "C" char DAT_004342e8[];
extern "C" char DAT_004342fc[];
struct Callback_3350f0 {
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
};
extern void __fastcall helper(Callback_3350f0*);
Callback_3350f0* __fastcall FUN_003350f0(Callback_3350f0* p) {
    p->a = ((hulk_intptr)DAT_0042afa8);
    p->b = *(volatile int*)((hulk_intptr)((char*)&DAT_004cdbb0));
    helper(p);
    p->c = ((hulk_intptr)DAT_0042bf6c);
    p->a = ((hulk_intptr)DAT_004342fc);
    p->c = ((hulk_intptr)DAT_004342e8);
    p->d = 0;
    return p;
}