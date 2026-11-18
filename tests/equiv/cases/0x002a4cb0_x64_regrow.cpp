// eq64 must pass (integ2, D107): 0x002a4cb0's shape. The group array is allocated with count * sizeof(Group) (16 bytes
// on i386, 32 on x86-64) and a second allocation follows it; the 64-bit request outgrows the region the 32-bit run's
// request reserved, so the checker gives it its own (Heap.regrow) instead of laying its tail over the next object.
//
#include "tree_prelude.h"
extern "C" void* __cdecl FUN_0008d6d0(int size);   // the game's allocator (unk_08ceb0.cpp)
struct Group_rg {
    void* drawable;
    void* begin;
    void* end;
    int flags;
};
struct Buffer_rg {
    Group_rg* begin;
    Group_rg* end;
    Group_rg* spare;
};
extern "C" Buffer_rg* __cdecl Fill_002a4cb0(Buffer_rg* b, unsigned int count)
{
    if (count == 0 || count > 0x1000)
        return 0;
    b->begin = (Group_rg*)FUN_0008d6d0(count * sizeof(Group_rg));
    b->spare = (Group_rg*)FUN_0008d6d0(sizeof(Group_rg));
    if (b->begin == 0 || b->spare == 0)
        return 0;
    b->spare->flags = 7;
    b->end = b->begin + count;
    for (Group_rg* p = b->begin; p != b->end; ++p) {
        p->drawable = 0;
        p->begin = 0;
        p->end = 0;
        p->flags = 1;
    }
    return b;
}
