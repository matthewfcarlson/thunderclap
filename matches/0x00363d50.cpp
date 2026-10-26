#include "decls/data/game/global.h"

#include "compat/ptr.h"
extern "C" void __cdecl freeItem(void*);
struct Pair {
    int a, b;
};
void FUN_00363d50() {
    Pair* p = ((Pair*)((char*)&DAT_004ddab0 + 4));
    int n = 13;
    do {
        --p;
        hulk_intptr v = p[0].a;
        if (v) {
            freeItem((void*)v);
            p[-1].b = 0;
            p[0].a = 0;
        }
    } while (--n);
}