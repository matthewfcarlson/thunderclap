#include "compat/ptr.h"
extern "C" char DAT_00433354[];
extern "C" char DAT_004333ac[];
typedef unsigned int U_326290;
extern void __stdcall Release(U_326290);
extern void __cdecl Dispose(U_326290);
struct d3dTexture_326290 {
    hulk_uintptr vt;
    char pad[12];
    U_326290 a;
    U_326290 b;
    U_326290 c;
    char gap[0x68 - 0x1c];
    U_326290 d;
    void BaseDestroy();
};
void __fastcall FUN_00326290(d3dTexture_326290* self) {
    self->vt = ((hulk_intptr)DAT_004333ac);
    if (self->a)
        Release(self->a);
    if (self->b) {
        Release(self->b);
        Dispose(self->b);
    }
    if (self->c) {
        Release(self->c);
        Dispose(self->c);
    }
    if (self->d)
        Release(self->d);
    self->vt = ((hulk_intptr)DAT_00433354);
    self->BaseDestroy();
}