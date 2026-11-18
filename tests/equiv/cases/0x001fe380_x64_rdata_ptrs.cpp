// eq64 must fail (integ2, D103): HULK_RDATA on a table of pointers (4 bytes on one target, 8 on the other): the
// XBE's bytes are no 64-bit value, unsupported.
//
#include "tree_prelude.h"
#include "decls/data/records.h"
extern "C" void *const DAT_00425260[4] HULK_RDATA;
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
    for (const int *tp = (const int *)DAT_00425260; tp < (const int *)DAT_00425260 + 4; tp++) {
        Lists_rd *l = f->lists[*tp];
        if (l)
            s += l->count;
    }
    return s;
}
