// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 23/26, incomplete)
// FUN_0030df50 @ 0x0030df50
struct Elem {
    char data[0xa4];
    Elem *FUN_0031a440();
    void FUN_0031a4f0(Elem *src);
    void FUN_0031a800();
};

struct Range {
    char pad0[0x10];
    int offset;
};

class Pool {
public:
    int FUN_0030df50();

    char pad0[4];
    Range *rangesBegin;
    Range *rangesEnd;
    char pad0c[0x24 - 0x0c];
    int *freeBegin;
    int *freeEnd;
    char pad2c[0x34 - 0x2c];
    Elem *elemBegin;
    Elem *elemEnd;
    Elem *elemCap;
};

int Pool::FUN_0030df50()
{
    if ((((char *)freeEnd - (char *)freeBegin) & ~3) != 0) {
        freeEnd = freeEnd - 1;
        return *freeEnd;
    }

    Elem tmp;
    Elem *added = 0;
    int count = elemEnd - elemBegin;

    if (count == 0) {
        Elem *src = tmp.FUN_0031a440();
        bool ok;
        Elem *end = elemEnd;
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
        return (int)added;
    }

    Elem *oldBegin = elemBegin;
    Elem *src = tmp.FUN_0031a440();
    bool ok;
    Elem *end = elemEnd;
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
        int delta = (char *)elemBegin - (char *)oldBegin;
        Range *r = rangesBegin;
        if (!(r > rangesEnd)) {
            Range *prev;
            do {
                r->offset += delta;
                prev = r;
                r++;
            } while (prev != rangesEnd);
        }
        for (unsigned i = 0; i < (unsigned)(freeEnd - freeBegin); i++)
            freeBegin[i] += delta;
    }
    return (int)added;
}
