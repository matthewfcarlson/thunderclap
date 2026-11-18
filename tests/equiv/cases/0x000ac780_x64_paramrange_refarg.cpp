// eq64 must fail (integ2, D102; rev5's d102d/refarg): the annotated parameter passed to a non-const reference (rev5_bump(int&))
// can be changed by the callee: no whole-argument exemption, refused.
#include "tree_prelude.h"
#include "decls/data/records.h"
void rev5_bump(int& x);
#define REV5_IDX(x) ((x) + 1)
struct Item_ac780 { virtual int g(void*); };
// heap id: an index into DAT_00527c60 (0x00527c60), call sites 0x26ffbf, 0x2704aa
extern "C" int FUN_000ac780(int index HULK_RANGE(0, 45), void* value) {
    rev5_bump(index);
    return ((Item_ac780*)DAT_00527c60[index].allocator)->g(value);
}
