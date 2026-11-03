#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* Alloc(hulk_uintptr);
extern "C" void Free(void*);
void owners::Thing_1c5f30::FUN_001c5f30(hulk_uintptr value) {
    unsigned int* p;
    unsigned int n;
    if (count >= capacity) {
        if (capacity == 0)
            capacity = 0x32;
        capacity = capacity * 2;
        p = (unsigned int*)Alloc(capacity * 4);
        if (data != 0) {
            n = 0;
            while (n < count) {
                p[n] = data[n];
                ++n;
            }
            Free(data);
        }
        data = p;
    }
    data[count] = ((unsigned int)value);
    ++count;
}