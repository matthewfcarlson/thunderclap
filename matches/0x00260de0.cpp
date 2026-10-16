#include "decls/data/engine/om.h"

typedef unsigned int U_260de0;
struct H {
    void* vt;
    char pad[0x44];
    void f(void*, void*, int, int);
    void g();
};
extern U_260de0 __cdecl f2475(void*);
extern char vft_260de0[];
U_260de0 __cdecl target() {
    H h;
    h.f((void*)((int)DAT_004e58d0), (void*)((int)DAT_004e58c8), 0x24, 4);
    h.vt = vft_260de0;
    U_260de0 r = f2475(&h);
    h.g();
    return r;
}
