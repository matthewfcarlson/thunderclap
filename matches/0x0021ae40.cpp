#include "compat/ptr.h"
void Grow(int a, int b, ...);
void* Move(int a, int b, int c, int d);
void* Resize(hulk_intptr a, hulk_intptr b, int* cnt, int size, int cap, hulk_intptr e) {
    int c = *cnt;
    int n = cap;
    if (c >= cap / 2) {
        if (c >= cap - 4)
            Grow(a, e);
    } else {
        n = c * 2;
        if (n < 4)
            n = 4;
    }
    void* r_ret = Move(a, b, *cnt * size, n * size);
    *cnt = n;
    return r_ret;
}
