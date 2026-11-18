// eq64 must pass (integ2, D103): a const .rdata table annotated HULK_RDATA: both runs start from its XBE bytes
// {2, 3, 4, 5}, every input indexes lists[] in range (equivalent).
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
    return s;
}
