// eq64 must fail (integ2, D107 follow-up (a); rev5's probe): an allocator whose size is a later, pointer-width parameter
// (Lua's luaM_realloc shape, 0x0021add0: L, block, oldsize, newsize) asked for 0xFFFF00000000 more bytes on x86-64
// only. Read at its declared width (8 bytes), the 64-bit request is out of bounds: layout. (Read as 4 bytes it
// matched the 32-bit one and the run passed.)
//
#include "tree_prelude.h"
extern "C" void* __cdecl FUN_0021add0(void* L, void* block, hulk_uintptr oldsize, hulk_uintptr newsize);
struct Group_aw {
    int a, b, c, d;
};
extern "C" Group_aw* __cdecl Grow_002a4cb0(void* L, unsigned int count)
{
    if (count == 0 || count > 0x1000)
        return 0;
    hulk_uintptr n = (hulk_uintptr)count * sizeof(Group_aw);
#if defined(HULK_PTR64)
    n += (hulk_uintptr)0xFFFF00000000ull;
#endif
    Group_aw* g = (Group_aw*)FUN_0021add0(L, 0, 0, n);
    if (g == 0)
        return 0;
    for (unsigned int i = 0; i < count; ++i)
        g[i].a = (int)i;
    return g;
}
