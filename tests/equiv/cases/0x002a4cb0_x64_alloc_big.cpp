// eq64 must fail (integ2, D107 follow-up (b); rev5's probe): the 64-bit side asks for 0x7ffffff0 bytes where the 32-bit one
// asks for count * 16: a 64-bit request past ALLOC_MAX (or far above the 32-bit one) is a gating layout stop.
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
    b->begin = (Group_rg*)FUN_0008d6d0(sizeof(void*) == 8 ? 0x7ffffff0 : (int)(count * sizeof(Group_rg)));
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
