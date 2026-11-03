#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void _ReadWriteBarrier();
void owners::Mapping_298a60::FUN_00298a60() {
    count = 0;
    _ReadWriteBarrier();
    hulk_uintptr n = last - first;
    unsigned i = 0;
    while (i < n) {
        if (first[i]) {
            forward[i] = count;
            reverse[count] = (unsigned char)i;
            ++count;
        } else {
            forward[i] = 255;
            reverse[i] = 255;
        }
        ++i;
    }
}