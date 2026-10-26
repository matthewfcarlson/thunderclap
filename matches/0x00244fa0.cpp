#include "decls/data/engine/om.h"
// data: g_context = DAT_004cc08c, g_enabled = DAT_004e5f0c

extern "C" int helper(void*, void*);
extern "C" int FUN_00244fa0(unsigned int* a, unsigned int* b) {
    if (!DAT_004e5f0c)
        return 0;
    unsigned int local[4];
    local[0] = a[0];
    local[1] = a[1];
    local[2] = b[0];
    local[3] = b[1];
    return helper((*(void**)&DAT_004cc08c), local);
}