#include "compat/ptr.h"
extern void __cdecl CopyThing(int, void*, int);
extern void __cdecl FinishThing(int, int);
struct Thing_339540 {
    int base;
    int count;
    int value;
};
void __cdecl FUN_00339540(Thing_339540* p) {
    hulk_intptr diff = p->base - (hulk_intptr)p - 12;
    if (diff != 0) {
        char* dst = (char*)p + 12;
        CopyThing(p->value, dst, diff);
        p->base = (hulk_intptr)dst;
        p->count = p->count + 1;
    }
    FinishThing(p->value, p->count);
    p->count = 1;
}