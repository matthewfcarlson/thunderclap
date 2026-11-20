// eq64 must fail (integ2, D103; rev5's R7): HULK_RDATA on an .rdata table data.json types as plain ints whose words
// fall inside the image's address range: they would be pointers natively, so the annotation is refused (unsupported).
// (integ3: was 0x0040cc74, whose odd words are image addresses; data.json now types that one GameLanguageName[6], a
// struct table, refused before the word scan. 0x0043a814 is int[7] {0x20002, ...}: words in the image range, the
// rule's conservative side)
//
#include "tree_prelude.h"
#include "decls/data/records.h"
namespace rd {
extern const int DAT_0043a814[7] HULK_RDATA;
}
struct Lists_rd {
    int count;
};
struct Finder_rd {
    Lists_rd *lists[64];
};
// 0x001fe380's shape: the object classes it gathers come from a const .rdata table
extern "C" int __cdecl Sum_001fe380(Finder_rd *f)
{
    int s = 0;
    for (const int *tp = rd::DAT_0043a814; tp < rd::DAT_0043a814 + 4; tp++) {
        Lists_rd *l = f->lists[*tp & 63];
        if (l)
            s += l->count;
    }
    return s;
}
