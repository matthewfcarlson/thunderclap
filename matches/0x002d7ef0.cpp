#include "compat/ptr.h"
extern "C" int FUN_002d7ef0(int a, hulk_intptr b) {
    if (a && b)
        return *(int*)(b + 4);
    return 0;
}