// Same code shape as 0x000f2740 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"
typedef unsigned int uint;
extern "C" void* __cdecl FUN_0008d690(uint);
struct FETextureAnimation_f2860 {
    int make(void*, void*);
};
struct Y_f2860 {
    int pad;
    void* field;
    void* slots[32];
    hulk_intptr f(void*);
};
hulk_intptr Y_f2860::f(void* p) {
    if (!field)
        return 0;
    FETextureAnimation* x = (FETextureAnimation*)FUN_0008d690(0x60);
    hulk_intptr r = x ? ((FETextureAnimation_f2860*)(x))->make(field, p) : 0;
    int i = 0;
    do {
        if (slots[i] == 0) {
            if (r)
                slots[i] = (void*)r;
            return r;
        }
        ++i;
    } while (i < 32);
    return r;
}
