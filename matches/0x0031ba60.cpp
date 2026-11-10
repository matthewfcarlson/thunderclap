#include "compat/ptr.h"
#include "decls/data/records.h"
#include "decls/data/platform/xbox/pure3d.h"
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" hulk_uintptr __stdcall FUN_0037d240(int);  // Direct3D_Object (XDK; the native tables bind it by address)
// The pddi d3dDevice wrapper (matches/0x0031ba00.cpp initializes it: vftable, two words, the D3D object, a flag word).
struct d3dDevice_31ba60 {
    hulk_uintptr vftable;
    char pad4[8];
    unsigned int fieldC;
    unsigned int field10;
    d3dDevice_31ba60* FUN_0031ba00(hulk_uintptr d3d);
};
// The pddi driver's device probe: (18, 11) is the Xbox D3D device. The wrapper is created once and kept in the slot
// DAT_005554a4 (a pointer word: config/data-ptrs.json); it is returned through `out`, a pointer.
int FUN_0031ba60(int a, int b, d3dDevice_31ba60** out) {
    if (a == 0x12 && b == 0xb) {
        d3dDevice_31ba60* value = *(d3dDevice_31ba60**)&DAT_005554a4;
        if (!value) {
            HULK_SIZE32(d3dDevice_31ba60, 0x14);
            d3dDevice_31ba60* p = (d3dDevice_31ba60*)FUN_0008d690((unsigned int)sizeof(d3dDevice_31ba60));
            if (p)
                value = p->FUN_0031ba00(FUN_0037d240(0));
            else
                value = 0;
            *(d3dDevice_31ba60**)&DAT_005554a4 = value;
        }
        *out = value;
        return 1;
    }
    *out = 0;
    return 100;
}
