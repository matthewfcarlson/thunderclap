#include "compat/ptr.h"
int Compare(int, int);
int Build(int, int);
int Target(hulk_intptr a, int b, int c) {
    int r = Compare(a, b);
    if (r <= 0)
        return c;
    return Build(a, b);
}