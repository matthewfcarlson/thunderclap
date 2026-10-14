// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 61/62, incomplete)
// FUN_002299c0 @ 0x002299c0
// std::_Unguarded_partition over 12-byte elements ordered descending by the float at +4
struct Elem_2299c0 {
    float a;
    float key;
    float c;
};

struct Range_2299c0 {
    Elem_2299c0 *first;
    Elem_2299c0 *second;
    Range_2299c0(Elem_2299c0 *f, Elem_2299c0 *s) : first(f), second(s) {}
};

void FUN_00229840(Elem_2299c0 *first, Elem_2299c0 *mid, Elem_2299c0 *last);

static inline bool Before(const Elem_2299c0 &x, const Elem_2299c0 &y)
{
    return x.key > y.key;
}

static inline void Swap(Elem_2299c0 *x, Elem_2299c0 *y)
{
    Elem_2299c0 t = *x;
    *x = *y;
    *y = t;
}

Range_2299c0 FUN_002299c0(Elem_2299c0 *first, Elem_2299c0 *last)
{
    Elem_2299c0 *mid = first + (last - first) / 2;
    FUN_00229840(first, mid, last - 1);
    Elem_2299c0 *pfirst = mid;
    Elem_2299c0 *plast = pfirst + 1;
    while (first < pfirst && !Before(pfirst[-1], *pfirst) && !Before(*pfirst, pfirst[-1])) {
        --pfirst;
    }
    while (plast < last && !Before(*plast, *pfirst) && !Before(*pfirst, *plast)) {
        ++plast;
    }
    Elem_2299c0 *gfirst = plast;
    Elem_2299c0 *glast = pfirst;
    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (Before(*pfirst, *gfirst)) {
            } else if (Before(*gfirst, *pfirst)) {
                break;
            } else {
                Swap(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (Before(glast[-1], *pfirst)) {
            } else if (Before(*pfirst, glast[-1])) {
                break;
            } else {
                Swap(--pfirst, glast - 1);
            }
        }
        if (glast == first && gfirst == last) {
            return Range_2299c0(pfirst, plast);
        }
        if (glast == first) {
            if (plast != gfirst) {
                Swap(pfirst, plast);
            }
            ++plast;
            Swap(pfirst++, gfirst++);
        } else if (gfirst == last) {
            if (--glast != --pfirst) {
                Swap(glast, pfirst);
            }
            Swap(pfirst, --plast);
        } else {
            Swap(gfirst++, --glast);
        }
    }
}
