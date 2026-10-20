// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 23/26, incomplete)
// FUN_0030df50 @ 0x0030df50
#include "compat/ptr.h"
struct Elem_30df50 {
    char data[0xa4];
    Elem_30df50 *FUN_0031a440();
    void FUN_0031a4f0(Elem_30df50 *src);
    void FUN_0031a800();
};

struct Range_30df50 {
    char pad0[0x10];
    int offset;
};

class Pool_30df50 {
public:
    int FUN_0030df50();

    char pad0[4];
    Range_30df50 *rangesBegin;
    Range_30df50 *rangesEnd;
    char pad0c[0x24 - 0x0c];
    int *freeBegin;
    int *freeEnd;
    char pad2c[0x34 - 0x2c];
    Elem_30df50 *elemBegin;
    Elem_30df50 *elemEnd;
    Elem_30df50 *elemCap;
};

int Pool_30df50::FUN_0030df50()
{
    if ((((char *)freeEnd - (char *)freeBegin) & ~3) != 0) {
        freeEnd = freeEnd - 1;
        return *freeEnd;
    }

    Elem_30df50 tmp;
    Elem_30df50 *added = 0;
    hulk_intptr count = elemEnd - elemBegin;

    if (count == 0) {
        Elem_30df50 *src = tmp.FUN_0031a440();
        bool ok;
        Elem_30df50 *end = elemEnd;
        if (end < elemCap) {
            elemEnd = end + 1;
            if (end)
                end->FUN_0031a4f0(src);
            ok = true;
        } else {
            ok = false;
        }
        tmp.FUN_0031a800();
        if (ok)
            added = elemEnd - 1;
        return (hulk_intptr)added;
    }

    Elem_30df50 *oldBegin = elemBegin;
    Elem_30df50 *src = tmp.FUN_0031a440();
    bool ok;
    Elem_30df50 *end = elemEnd;
    if (end < elemCap) {
        elemEnd = end + 1;
        if (end)
            end->FUN_0031a4f0(src);
        ok = true;
    } else {
        ok = false;
    }
    tmp.FUN_0031a800();
    if (ok)
        added = elemEnd - 1;

    if (oldBegin != elemBegin) {
        hulk_intptr delta = (char *)elemBegin - (char *)oldBegin;
        Range_30df50 *r = rangesBegin;
        if (!(r > rangesEnd)) {
            Range_30df50 *prev;
            do {
                r->offset += delta;
                prev = r;
                r++;
            } while (prev != rangesEnd);
        }
        for (unsigned i = 0; i < (unsigned)(freeEnd - freeBegin); i++)
            freeBegin[i] += delta;
    }
    return (hulk_intptr)added;
}
