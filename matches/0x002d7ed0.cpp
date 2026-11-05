#include "compat/ptr.h"
extern "C" int FUN_002d7ed0(hulk_intptr a, int* b) {
    if (a && b)
        return *b;
    return 0;
}