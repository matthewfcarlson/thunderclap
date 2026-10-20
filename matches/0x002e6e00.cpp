#include "compat/ptr.h"
typedef unsigned int u32_2e6e00;
struct Obj_2e6e00 {
    char pad0[0x1c];
    hulk_intptr field1c;
    char pad20[4];
    int(__cdecl* callback)(int, int);
    int field28;
};
void Cleanup(int, Obj_2e6e00*);
int __cdecl Target(Obj_2e6e00* p) {
    if (p && p->field1c && p->callback) {
        int v = *(int*)(p->field1c + 0x14);
        if (v)
            Cleanup(v, p);
        p->callback(p->field28, p->field1c);
        p->field1c = 0;
        return 0;
    }
    return -2;
}