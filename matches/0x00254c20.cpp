#include "compat/ptr.h"
extern "C" char DAT_0042a3e4[];
struct SeqEventContainer_254c20 {
    SeqEventContainer_254c20();
};
struct SeqEventLogicRepeat : SeqEventContainer_254c20 {
    char pad[8];
    int a[5];
    SeqEventLogicRepeat();
};
SeqEventLogicRepeat::SeqEventLogicRepeat() {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 1;
    a[4] = 1;
    *(void**)this = (void*)((hulk_intptr)DAT_0042a3e4);
}