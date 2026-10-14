// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 61/62, incomplete)
// FUN_00227a10 @ 0x00227a10
// std::_Unguarded_partition over 12-byte elements ordered descending by the float at +4
struct Elem {
    float a;
    float key;
    float c;
};

struct Range {
    Elem *first;
    Elem *second;
    Range(Elem *f, Elem *s) : first(f), second(s) {}
};

void FUN_00227750(Elem *first, Elem *mid, Elem *last);

static inline bool Before(const Elem &x, const Elem &y)
{
    return x.key > y.key;
}

static inline void Swap(Elem *x, Elem *y)
{
    Elem t = *x;
    *x = *y;
    *y = t;
}

Range FUN_00227a10(Elem *first, Elem *last)
{
    Elem *mid = first + (last - first) / 2;
    FUN_00227750(first, mid, last - 1);
    Elem *pfirst = mid;
    Elem *plast = pfirst + 1;
    while (first < pfirst && !Before(pfirst[-1], *pfirst) && !Before(*pfirst, pfirst[-1])) {
        --pfirst;
    }
    while (plast < last && !Before(*plast, *pfirst) && !Before(*pfirst, *plast)) {
        ++plast;
    }
    Elem *gfirst = plast;
    Elem *glast = pfirst;
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
            return Range(pfirst, plast);
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
