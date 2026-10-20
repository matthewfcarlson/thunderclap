// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// FUN_002e5330 @ 0x002e5330
#include "compat/ptr.h"
class SortedArray {
public:
    char pad0[8];
    unsigned int* begin;
    unsigned int* end;
    bool FUN_002e5330(unsigned int key, unsigned int* outIndex);
};
bool SortedArray::FUN_002e5330(unsigned int key, unsigned int* outIndex) {
    unsigned int* b = begin;
    hulk_intptr n = end - b;
    if (n == 0)
        return false;
    if (key < b[0] || key > b[n - 1])
        return false;
    hulk_uintptr lo = 0;
    hulk_uintptr hi = n - 1;
    hulk_uintptr mid = hi >> 1;
    for (;;) {
        if (mid > hi)
            return false;
        unsigned int v = b[mid];
        if (key == v) {
            if (outIndex)
                *outIndex = mid;
            return true;
        }
        if (key < v)
            hi = mid - 1;
        else
            lo = mid + 1;
        mid = (hi + lo) >> 1;
        if (lo > mid)
            return false;
    }
}
