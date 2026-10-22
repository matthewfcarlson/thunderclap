#include "compat/ptr.h"
extern "C" char DAT_004323e4[];
extern "C" char DAT_0043242c[];
typedef unsigned int u32_31acf0;
extern void __stdcall D3DDevice_Release();
extern void __stdcall D3DResource_Release(u32_31acf0);
struct d3dDisplay_31acf0 {
    hulk_uintptr vptr;
    char pad[0x0c];
    u32_31acf0 device;
    char pad2[0x484];
    u32_31acf0 resource;
    void Finish();
};
void __fastcall FUN_0031acf0(d3dDisplay_31acf0* self) {
    u32_31acf0 d = self->device;
    self->vptr = ((hulk_intptr)DAT_0043242c);
    if (d)
        D3DDevice_Release();
    u32_31acf0 r = self->resource;
    if (r)
        D3DResource_Release(r);
    self->vptr = ((hulk_intptr)DAT_004323e4);
    self->Finish();
}