// STATUS: equivalent (tools/equiv.py level 3: 156 inputs, branch coverage 97/106, incomplete)
// FUN_00223870 @ 0x00223870
struct Elem_223870 {
    char pad00[0xc];
    unsigned k0;
    unsigned k1;
    int hi;
    char pad18[0x28 - 0x18];
};

struct ElemPair_223870 {
    Elem_223870 *first;
    Elem_223870 *second;
};

void __cdecl FUN_002236c0(Elem_223870 *first, Elem_223870 *mid, Elem_223870 *last);

static bool Less(const Elem_223870 &a, const Elem_223870 &b)
{
    if (a.hi != b.hi)
        return a.hi > b.hi;
    if (a.k0 != b.k0)
        return a.k0 < b.k0;
    return a.k1 > b.k1;
}

static void IterSwap(Elem_223870 *a, Elem_223870 *b)
{
    Elem_223870 t = *a;
    *a = *b;
    *b = t;
}

// std::_Unguarded_partition on a 40-byte element
ElemPair_223870 *__cdecl FUN_00223870(ElemPair_223870 *out, Elem_223870 *first, Elem_223870 *last)
{
    Elem_223870 *mid = first + (last - first) / 2;
    FUN_002236c0(first, mid, last - 1);

    Elem_223870 *pfirst = mid;
    Elem_223870 *plast = pfirst + 1;
    while (first < pfirst && !Less(pfirst[-1], *pfirst) && !Less(*pfirst, pfirst[-1]))
        --pfirst;
    while (plast < last && !Less(*plast, *pfirst) && !Less(*pfirst, *plast))
        ++plast;

    Elem_223870 *gfirst = plast;
    Elem_223870 *glast = pfirst;
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
