// eq64 must fail (integ2, D103; rev5's R1): HULK_RANGE(0, 3) on the table whose XBE image holds {2, 3, 4, 5}: the
// game's own initial words break the claim, unsupported.
//
#include "tree_prelude.h"
#include "decls/data/records.h"
// only reader 0x001fe380
extern "C" const int DAT_00425260[4] HULK_RANGE(0, 3);
struct Lists_rd {
    int count;
};
struct Finder_rd {
    Lists_rd *lists[64];
};
// 0x001fe380's shape: the object classes it gathers come from the const .rdata table {2, 3, 4, 5}
extern "C" int __cdecl Sum_001fe380(Finder_rd *f)
{
    int s = 0;
    for (const int *tp = DAT_00425260; tp < DAT_00425260 + 4; tp++) {
        Lists_rd *l = f->lists[*tp];
        if (l)
            s += l->count;
    }
    return s;
}
