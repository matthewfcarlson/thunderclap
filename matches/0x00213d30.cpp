#include "compat/ptr.h"
typedef unsigned int u32_213d30;
struct Obj_213d30 {
    char pad0[8];
    u32_213d30* out;
    char padc[4];
    u32_213d30* state;
};
extern void helper17440(Obj_213d30*);
extern "C" void * __cdecl FUN_002194d0(void *, void *);
extern "C" int __cdecl FUN_00213d30(Obj_213d30* p, int a) {
    if (p->state[0x4c / 4] >= p->state[0x48 / 4])
        helper17440(p);
    int r = ((int)(hulk_uintptr)FUN_002194d0((Obj_213d30 *)p, (void *)(hulk_uintptr)(int)a));
    u32_213d30* q = p->out;
    q[1] = r;
    q[0] = 7;
    p->out += 2;
    return r + 0x10;
}