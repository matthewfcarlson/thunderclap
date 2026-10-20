#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042e574[];
struct ShadowSkinTopology {
    void* vptr;
    int pad4;
    void* a;
    void* b;
    void* c;
    void Reset();
};
void ReleaseThing(void*);
void ShadowSkinTopology::Reset() {
    vptr = (void*)((hulk_intptr)DAT_0042e574);
    ReleaseThing(a);
    ReleaseThing(b);
    ReleaseThing(c);
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}