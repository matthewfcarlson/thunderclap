#include "compat/ptr.h"
struct Item {
    char pad[0x38];
    volatile hulk_intptr a;
    int b;
};
extern "C" void FUN_00266eb0(int, int, int);
extern "C" void FUN_002474c0(int unused, Item* p) {
    int a = p->a;
    FUN_00266eb0(0, a, p->b);
}