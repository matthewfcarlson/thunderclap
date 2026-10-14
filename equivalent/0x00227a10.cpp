// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 61/62, incomplete)
// FUN_00227a10 @ 0x00227a10
// std::_Unguarded_partition over 12-byte elements ordered descending by the float at +4
struct Elem_227a10 {
    float a;
    float key;
    float c;
};

struct Range_227a10 {
    Elem_227a10 *first;
    Elem_227a10 *second;
    Range_227a10(Elem_227a10 *f, Elem_227a10 *s) : first(f), second(s) {}
};

void FUN_00227750(Elem_227a10 *first, Elem_227a10 *mid, Elem_227a10 *last);

static inline bool Before(const Elem_227a10 &x, const Elem_227a10 &y)
{
    return x.key > y.key;
}

static inline void Swap(Elem_227a10 *x, Elem_227a10 *y)
{
    Elem_227a10 t = *x;
    *x = *y;
    *y = t;
}

Range_227a10 FUN_00227a10(Elem_227a10 *first, Elem_227a10 *last)
{
    Elem_227a10 *mid = first + (last - first) / 2;
    FUN_00227750(first, mid, last - 1);
    Elem_227a10 *pfirst = mid;
    Elem_227a10 *plast = pfirst + 1;
    while (first < pfirst && !Before(pfirst[-1], *pfirst) && !Before(*pfirst, pfirst[-1])) {
        --pfirst;
    }
    while (plast < last && !Before(*plast, *pfirst) && !Before(*pfirst, *plast)) {
        ++plast;
    }
    Elem_227a10 *gfirst = plast;
    Elem_227a10 *glast = pfirst;
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
            return Range_227a10(pfirst, plast);
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
