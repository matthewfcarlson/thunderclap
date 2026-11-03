#include "gen/owners.h"
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void owners::Obj_1cbd40::FUN_001cbd40(unsigned int* dst, unsigned int* src) {
    unsigned int* end = mEnd;
    unsigned int* out = dst;
    while (src != end) {
        memcpy(out, src, 0xe0);
        src += 0x38;
        out += 0x38;
    }
    mEnd = out;
}