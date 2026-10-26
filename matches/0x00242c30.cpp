#include "decls/data/engine/unknown.h"
// data: gData_242c30 = DAT_004e5df8

extern "C" void* __cdecl FUN_00247530(void*);
extern "C" void __cdecl FUN_002422e0(int, void*, int*);
extern "C" void __cdecl FUN_00257e80(int, void*);
struct Obj_242c30 {
    char pad[0x18];
    int a, b, c, d, e, f, g, h;
};
extern "C" Obj_242c30* __cdecl FUN_00242c30(int param_1, int param_2) {
    Obj_242c30* q = (Obj_242c30*)FUN_00247530(((int*)&DAT_004e5df8));
    Obj_242c30* p;
    if (q) {
        q->a = 0;
        q->b = 0;
        p = q;
    } else
        p = 0;
    int zero = 0;
    p->d = param_1;
    p->f = zero;
    p->g = 0x3f800000;
    p->e = zero;
    p->c = param_2;
    p->h = zero;
    FUN_002422e0(param_1 + 0x14, p, &p->c);
    FUN_00257e80(param_2 + 0x28, (char*)p + 0x10);
    return p;
}