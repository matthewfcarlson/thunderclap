// eq64 must fail (integ2, D103; rev5's R2): HULK_RDATA on DAT_00425260[8], which reaches into the vftable at
// 0x00425270: no data.json item of 32 bytes there, unsupported.
//
#include "tree_prelude.h"
#include "decls/data/records.h"
extern "C" const int DAT_00425260[8] HULK_RDATA;
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
