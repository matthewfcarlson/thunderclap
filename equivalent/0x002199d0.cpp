// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 14/14)
// computesizes: the array size (a power of 2 more than half used) for the integer keys counted per power of 2.
#include "decls/data/lua.h"

// equiv-conv: FUN_002199d0 edx stack stack stack
extern "C" void __cdecl FUN_002199d0(int* nums, int ntotal, int* narray, int* nhash) {
    int a = nums[0];
    int na = a;
    int n = (a != 0) ? 0 : -1;
    int limit = *narray;
    if (a < limit) {
        const int* p = nums + 1;
        int i = 0;
        do {
            int twotoi = 1 << i;
            if (limit < twotoi)
                break;
            int count = *p;
            if (count > 0) {
                a += count;
                if (a >= twotoi) {
                    n = i + 1;
                    na = a;
                }
            }
            p++;
            i++;
        } while (a < *narray);
    }
    *nhash = ntotal - na;
    if (n == -1)
        *narray = 0;
    else
        *narray = 1 << n;
}
