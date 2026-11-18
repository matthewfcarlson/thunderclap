// eq64 must fail (integ2, D107): the same with a hard-coded 16-byte element size (count * 16): the 64-bit loop writes
// past the end of the 64-bit allocation, a real overrun: layout.
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
    b->begin = (Group_rg*)FUN_0008d6d0(count * 16);
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
