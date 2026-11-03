// Same code shape as 0x00290790 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
extern void* Alloc(hulk_uintptr);
extern "C" int * __cdecl FUN_002a7f30(int *, int, const int *);


bool owners::Buffer_2a8000::FUN_002a8000(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002a7f30((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}