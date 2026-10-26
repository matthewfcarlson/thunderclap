#include "decls/data/game/global.h"

extern "C" void A(void*, int);
extern "C" void B(void*, int, const char*, int);
extern "C" void C(void*, int);
extern "C" void D(void*, const char*);
extern "C" void E(void*, const char*, int);
extern "C" void F(void*, int);
extern "C" void G(void*, int);
extern "C" const char v2_1d07b0[];
extern "C" int FUN_001d07b0(void* p) {
    A(p, -10001);
    B(p, 0, ((const char*)&DAT_004223c8), 0);
    C(p, -2);
    D(p, DAT_00422404);
    B(p, 0, ((const char*)&DAT_004223d8), 0);
    E(p, DAT_00421bb4, 1);
    F(p, 0);
    G(p, -3);
    E(p, DAT_00421bb0, 1);
    F(p, 0x3f800000);
    G(p, -3);
    E(p, DAT_00421bac, 1);
    F(p, 0x40000000);
    G(p, -3);
    C(p, -2);
    return 0;
}