#include "compat/ptr.h"
extern "C" char hulk_at_004e6698[];
extern void FUN_00247530(void*);
void FUN_0024e660(void* x) {
    x = (void*)((hulk_intptr)hulk_at_004e6698);
    FUN_00247530(x);
}
