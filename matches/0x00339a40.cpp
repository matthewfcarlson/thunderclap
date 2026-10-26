#include "compat/ptr.h"
struct Item {
    hulk_intptr a;
    int b;
};
int* __cdecl FUN_00339a40(int dummy, Item* p, int* out) {
    int b = p->b;
    if (!b)
        return 0;
    *out = b;
    p->b = 0;
    return (int*)p->a;
}
