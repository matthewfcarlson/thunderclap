// Same code shape as 0x00290790 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void* FUN_0008d6d0(hulk_uintptr);
extern "C" int * __cdecl FUN_002a1010(int *, int, const int *);


bool owners::Buffer_2a10a0::FUN_002a10a0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)FUN_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002a1010((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}