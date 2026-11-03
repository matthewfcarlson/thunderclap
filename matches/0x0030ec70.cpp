#include "gen/owners.h"
extern "C" void* __cdecl Allocate(unsigned int);
bool owners::Buffer_30ec70::FUN_0030ec70(hulk_uintptr value) {
    if (data == 0) {
        data = (unsigned int*)Allocate(count << 2);
        count = 0;
    }
    data[count] = ((unsigned int)value);
    ++count;
    return true;
}