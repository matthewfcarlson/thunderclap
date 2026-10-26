#include "decls/data/engine/unknown.h"
// data: gPool_242bd0 = DAT_004e5db0

#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern void* __cdecl FUN_00247530(void*);
struct Node {
    int a[10];
};
Node* __cdecl FUN_00242bd0() {
    Node* p = (Node*)FUN_00247530(DAT_004e5db0);
    if (p) {
        int* q = (int*)p + 1;
        q[0] = (hulk_intptr)q;
        ((hulk_intptr*)p)[2] = (hulk_intptr)q;
        ((hulk_intptr*)p)[3] = (hulk_intptr)q;
        ((hulk_intptr*)p)[0] = (hulk_intptr)q;
        ((int*)p)[4] = 0;
        _ReadWriteBarrier();
        int* r = (int*)p + 6;
        r[0] = (hulk_intptr)r;
        ((hulk_intptr*)p)[7] = (hulk_intptr)r;
        ((hulk_intptr*)p)[8] = (hulk_intptr)r;
        ((int*)p)[9] = 0;
        ((hulk_intptr*)p)[5] = (hulk_intptr)r;
        return p;
    }
    return 0;
}
