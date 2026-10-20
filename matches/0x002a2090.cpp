#include "compat/ptr.h"
void FUN_002a1e60(hulk_intptr, hulk_intptr, hulk_intptr, int, int);
void FUN_002a2090(hulk_intptr first, int last, int arg) {
    hulk_intptr count = (last - first) >> 2;
    hulk_intptr i = count / 2;
    while (i > 0) {
        --i;
        FUN_002a1e60(first, i, count, ((int*)first)[i], arg);
    }
}