#include "compat/ptr.h"
typedef unsigned int uint;
struct Buffer {
    char pad[0x1c];
    uint start;
    uint size;
    unsigned char* pos;
    unsigned char valid;
};
extern "C" void* memcpy(void*, const void*, unsigned int);
bool __cdecl FUN_00246ab0(Buffer* b, const void* src, uint count) {
    if (!b->valid)
        return false;
    if (b->start + b->size - (hulk_uintptr)b->pos < count)
        return false;
    memcpy(b->pos, src, count);
    b->pos += count;
    return true;
}