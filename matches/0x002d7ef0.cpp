#include "compat/ptr.h"
int Target(int a, hulk_intptr b) {
    if (a && b)
        return *(int*)(b + 4);
    return 0;
}