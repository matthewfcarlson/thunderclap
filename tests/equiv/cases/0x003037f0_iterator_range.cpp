struct Item {
    unsigned int w[9];
    float key;
    unsigned int w2[7];
};
struct Partition {
    Item *first;
    Item *second;
};
void __cdecl FUN_00303700(Item *first, Item *mid, Item *last);

static inline bool Pred(const Item &a, const Item &b)
{
    return a.key < b.key;
}

static inline void IterSwap(Item *a, Item *b)
{
    Item t = *a;
    *a = *b;
    *b = t;
}

void __cdecl FUN_003037f0(Partition *result, Item *first, Item *last)
{
    Item *mid = first + (last - first) / 2;
    FUN_00303700(first, mid, last - 1);
    Item *pfirst = mid;
    Item *plast = pfirst + 1;

    while (first < pfirst && !Pred(*(pfirst - 1), *pfirst) && !Pred(*pfirst, *(pfirst - 1)))
        --pfirst;
    while (plast < last && !Pred(*plast, *pfirst) && !Pred(*pfirst, *plast))
        ++plast;

    Item *gfirst = plast;
    Item *glast = pfirst;

    for (;;) {
        for (; gfirst < last; ++gfirst) {
            if (Pred(*pfirst, *gfirst)) {
            } else if (Pred(*gfirst, *pfirst)) {
                break;
            } else {
                IterSwap(plast++, gfirst);
            }
        }
        for (; first < glast; --glast) {
            if (Pred(*(glast - 1), *pfirst)) {
            } else if (Pred(*pfirst, *(glast - 1))) {
                break;
            } else {
                IterSwap(--pfirst, glast - 1);
            }
        }
        if (glast == first && gfirst == last) {
            result->first = pfirst;
            result->second = plast;
            return;
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
