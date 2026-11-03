// Same code shape as 0x00290790 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
extern void* Alloc(hulk_uintptr);
extern "C" void FUN_002e1440(void*, unsigned int, void*);


bool owners::Buffer_2e16f0::FUN_002e16f0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002e1440(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}