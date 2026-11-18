// eq64 must fail (integ2, D103; rev5's R7): HULK_RDATA on the .rdata table 0x0040cc74, which data.json types int[]
// but whose odd words are image addresses ({0, 0x409598, 1, 0x40c374, ...}): pointers natively, unsupported.
//
#include "tree_prelude.h"
#include "decls/data/records.h"
namespace rd {   // (records.h declares the C name as GameLanguageName[6]: the words read as ints here)
extern const int DAT_0040cc74[12] HULK_RDATA;
}
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
    for (const int *tp = rd::DAT_0040cc74; tp < rd::DAT_0040cc74 + 4; tp++) {
        Lists_rd *l = f->lists[*tp];
        if (l)
            s += l->count;
    }
    return s;
}
