// Same code shape as 0x002b0fb0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/owners.h"
extern void* Alloc(hulk_uintptr);
extern "C" unsigned int * __cdecl FUN_002f98c0(unsigned int *, unsigned int, unsigned int *);
bool owners::Buffer_2f9b60::FUN_002f9b60(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        begin = (int*)Alloc(count * 8);
        if (begin != 0) {
            end = (int*)((char*)begin + count * 8);
            FUN_002f98c0((unsigned int *)(void *)begin, count, (unsigned int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}