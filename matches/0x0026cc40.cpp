#include "compat/ptr.h"
#include "gen/core.h"

// Release: the last reference frees the arena if the allocator owns it (+0x49c), then deletes the allocator (slot 2
// with 1) or, when it sits in memory it does not own (+0x49d), only destroys it (slot 2 with 0)
struct Slots_26cc40 {
    virtual void s0();
    virtual void s1();
    virtual void destroy(int flags);
};
extern "C" int FUN_00267090(hulk_intptr);
void core::MemoryDlAllocator::vfunc_1() {
    if (f_4a0 == 1) {
        if (f_49c == 1)
            FUN_00267090(f_0c);
        if (f_49d == 0)
            ((Slots_26cc40*)this)->destroy(1);
        else
            ((Slots_26cc40*)this)->destroy(0);
    } else
        --f_4a0;
}
