// eq64 must fail (integ2, D102; rev5's d102d/ctorinit): HULK_RANGE on a constructor's parameter used as index + 1 in a
// member initializer: the initializers are uses too, refused ("can't be derived from its uses").
#include "tree_prelude.h"
#include "decls/data/records.h"
void rev5_bump(int& x);
#define REV5_IDX(x) ((x) + 1)
struct Item_ac780 { virtual int g(void*); };
struct Holder_ac780 {
    void* v;
    // heap id: an index into DAT_00527c60 (0x00527c60), call sites 0x26ffbf
    Holder_ac780(int index HULK_RANGE(0, 45));
};
// heap id: an index into DAT_00527c60 (0x00527c60), call sites 0x26ffbf
Holder_ac780::Holder_ac780(int index HULK_RANGE(0, 45)) : v(DAT_00527c60[index + 1].allocator) {
    if (index < 0) v = 0;
}
