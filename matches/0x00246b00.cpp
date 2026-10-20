#include "compat/ptr.h"
typedef unsigned int uint;
extern "C" void* memcpy(void*, const void*, uint);
struct Buf {
    char pad[0x1c];
    uint a;
    uint b;
    char* cur;
    char flag;
};
bool __cdecl FUN_00246b00(Buf* p, void* dst, uint n) {
    if (p->flag)
        return false;
    if (p->a + p->b - (hulk_uintptr)p->cur < n)
        return false;
    memcpy(dst, p->cur, n);
    p->cur += n;
    return true;
}