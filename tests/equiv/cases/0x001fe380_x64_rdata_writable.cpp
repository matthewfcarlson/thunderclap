// eq64 must fail (integ2, D103): HULK_RDATA on a const declaration of a table in .data (the Perlin permutation
// table: writable section, zero fill): unsupported.
//
#include "tree_prelude.h"
#include "decls/data/records.h"
extern "C" const int DAT_0056bfc8[514] HULK_RDATA;
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
    for (const int *tp = DAT_0056bfc8; tp < DAT_0056bfc8 + 4; tp++) {
        Lists_rd *l = f->lists[*tp];
        if (l)
            s += l->count;
    }
    return s;
}
