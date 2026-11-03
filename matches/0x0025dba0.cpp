#include "compat/ptr.h"
#include "gen/owners.h"

void owners::Queue_25dba0::FUN_0025dba0(int* item) {
    int* node = item + 1;
    *node = 0;
    if (tail == 0) {
        head = node;
        tail = node;
    } else {
        *(hulk_intptr*)tail = (hulk_intptr)node;
        tail = node;
    }
}
