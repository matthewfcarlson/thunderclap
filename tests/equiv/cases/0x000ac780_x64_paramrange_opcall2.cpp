// eq64 must fail (integ2, D102; rev5's d102d/opcall2): a member operator call takes the annotated parameter by non-const reference
// (libclang counts the object as argument 0; matched against the right parameter it is refused).
#include "tree_prelude.h"
#include "decls/data/records.h"
struct Item_ac780 { virtual int g(void*); };
struct Bumper { void operator()(int& x, int y); };
// heap id: an index into DAT_00527c60 (0x00527c60), call sites 0x26ffbf
extern "C" int FUN_000ac780(int index HULK_RANGE(0, 45), void* value) {
    Bumper b;
    b(index, 0);
    return ((Item_ac780*)DAT_00527c60[index].allocator)->g(value);
}
