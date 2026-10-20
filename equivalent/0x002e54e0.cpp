// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002e54e0 @ 0x002e54e0
#include "compat/ptr.h"
void *FUN_0008d6d0(hulk_uintptr size);

struct IntVec2 {
    int *first;
    int *last;
    IntVec2(const IntVec2 &other) throw();
};

IntVec2::IntVec2(const IntVec2 &other) throw()
{
    hulk_intptr count = other.last - other.first;
    if (count != 0) {
        first = (int *)FUN_0008d6d0(count * 4);
        if (first != 0) {
            last = first + count;
            int *dst = first;
            const int *src = other.first;
            for (count = other.last - src; count != 0; count--) {
                if (dst != 0)
                    *dst = *src;
                src++;
                dst++;
            }
            return;
        }
    }
    first = 0;
    last = 0;
}
