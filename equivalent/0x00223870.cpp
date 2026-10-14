// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 97/106, incomplete)
// FUN_00223870 @ 0x00223870
struct Elem {
    char pad00[0xc];
    unsigned k0;
    unsigned k1;
    int hi;
    char pad18[0x28 - 0x18];
};

struct ElemPair {
    Elem *first;
    Elem *second;
};

void __cdecl FUN_002236c0(Elem *first, Elem *mid, Elem *last);

static bool Less(const Elem &a, const Elem &b)
{
    if (a.hi != b.hi)
        return a.hi > b.hi;
    if (a.k0 != b.k0)
        return a.k0 < b.k0;
    return a.k1 > b.k1;
}

static void IterSwap(Elem *a, Elem *b)
{
    Elem t = *a;
    *a = *b;
    *b = t;
}

// std::_Unguarded_partition on a 40-byte element
ElemPair *__cdecl FUN_00223870(ElemPair *out, Elem *first, Elem *last)
{
    Elem *mid = first + (last - first) / 2;
    FUN_002236c0(first, mid, last - 1);

    Elem *pfirst = mid;
    Elem *plast = pfirst + 1;
    while (first < pfirst && !Less(pfirst[-1], *pfirst) && !Less(*pfirst, pfirst[-1]))
        --pfirst;
    while (plast < last && !Less(*plast, *pfirst) && !Less(*pfirst, *plast))
        ++plast;

    Elem *gfirst = plast;
    Elem *glast = pfirst;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (Less(*pfirst, *gfirst)) {
            } else if (Less(*gfirst, *pfirst)) {
                break;
            } else {
                IterSwap(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (Less(glast[-1], *pfirst)) {
            } else if (Less(*pfirst, glast[-1])) {
                break;
            } else {
                IterSwap(--pfirst, glast - 1);
            }
        }
        if (glast == first && gfirst == last) {
            out->first = pfirst;
            out->second = plast;
            return out;
        }
        if (glast == first) {
            if (plast != gfirst)
                IterSwap(pfirst, plast);
            ++plast;
            IterSwap(pfirst++, gfirst++);
        } else if (gfirst == last) {
            if (--glast != --pfirst)
                IterSwap(glast, pfirst);
            IterSwap(pfirst, --plast);
        } else {
            IterSwap(gfirst++, --glast);
        }
    }
}
