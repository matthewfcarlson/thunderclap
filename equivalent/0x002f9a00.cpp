// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002f9a00 @ 0x002f9a00
#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);


owners::WideVector_2f9a00* owners::WideVector_2f9a00::FUN_002f9a00(const owners::WideVector_2f9a00* other) {
    hulk_intptr capacity = other->cap - other->first;
    if (capacity != 0) {
        first = (unsigned short*)FUN_0008d6d0(capacity * 2);
        if (first) {
            last = first;
            cap = first + capacity;
            const unsigned short* src = other->first;
            unsigned short* dst = first;
            for (hulk_intptr n = other->last - other->first; n != 0; n--) {
                if (dst)
                    *dst = *src;
                src++;
                dst++;
            }
            last = dst;
            return this;
        }
    } else {
        first = 0;
    }
    last = 0;
    cap = 0;
    return this;
}
