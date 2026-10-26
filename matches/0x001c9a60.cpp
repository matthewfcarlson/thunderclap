#include "compat/ptr.h"
extern "C" void* memset(void*, int, unsigned);
struct Item {
    volatile hulk_intptr a, b;
    int c, d;
    volatile int e;
    int f, g;
    Item(int x, int y, int z);
};
Item::Item(int x, int y, int z) {
    memset(this, 0, sizeof(*this));
    a = 28;
    b = 4;
    e = x;
    f = y;
    g = z;
}