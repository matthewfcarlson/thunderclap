#include "gen/owners.h"
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
bool owners::Buffer_2f9340::FUN_002f9340(unsigned int count) {
    if (count) {
        start = (short*)FUN_0008d6d0(count * sizeof(short));
        if (start) {
            end = start + count;
            current = start;
            return true;
        }
    } else {
        start = 0;
    }
    current = 0;
    end = 0;
    return false;
}