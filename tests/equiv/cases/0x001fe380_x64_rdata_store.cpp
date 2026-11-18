// eq64 must fail (integ2, D103): the function stores into its HULK_RDATA table (through a cast): the claim is
// refuted, unsupported.
//
#include "tree_prelude.h"
#include "decls/data/records.h"
extern "C" const int DAT_00425260[4] HULK_RDATA;
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
    ((int *)DAT_00425260)[1] = s;
    return s;
}
