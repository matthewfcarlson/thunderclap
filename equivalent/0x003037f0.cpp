// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 60/62, incomplete)
// FUN_003037f0 @ 0x003037f0
struct Item_3037f0 {
    unsigned int w[9];
    float key;
    unsigned int w2[7];
};
struct Partition {
    Item_3037f0 *first;
    Item_3037f0 *second;
};
void __cdecl FUN_00303700(Item_3037f0 *first, Item_3037f0 *mid, Item_3037f0 *last);

static inline bool Pred(const Item_3037f0 &a, const Item_3037f0 &b)
{
    return a.key < b.key;
}

static inline void IterSwap(Item_3037f0 *a, Item_3037f0 *b)
{
    Item_3037f0 t = *a;
    *a = *b;
    *b = t;
}

void __cdecl FUN_003037f0(Partition *result, Item_3037f0 *first, Item_3037f0 *last)
{
    Item_3037f0 *mid = first + (last - first) / 2;
    FUN_00303700(first, mid, last - 1);
    Item_3037f0 *pfirst = mid;
    Item_3037f0 *plast = pfirst + 1;

    while (first < pfirst && !Pred(*(pfirst - 1), *pfirst) && !Pred(*pfirst, *(pfirst - 1)))
        --pfirst;
    while (plast < last && !Pred(*plast, *pfirst) && !Pred(*pfirst, *plast))
        ++plast;

    Item_3037f0 *gfirst = plast;
    Item_3037f0 *glast = pfirst;

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
