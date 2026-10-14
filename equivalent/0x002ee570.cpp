// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 18/18)
// FUN_002ee570 @ 0x002ee570
struct Entry_2ee570 {
    void *a;
    void *b;
    int c, d, e;
};

struct Item_2ee570 {
    char pad00[0x50];
    unsigned char flag;
};

struct Maker_2ee570 {
    Entry_2ee570 data;
    Entry_2ee570 *FUN_002f8ef0(Item_2ee570 *x, Item_2ee570 *y);
};

class Graph_2ee570 {
public:
    char pad00[0x4c];
    Entry_2ee570 *begin;
    Entry_2ee570 *end;
    Entry_2ee570 *limit;
    void FUN_002ee570(Item_2ee570 *x, Item_2ee570 *y);
};

// Adds an edge between x and y unless one already connects them.
void Graph_2ee570::FUN_002ee570(Item_2ee570 *x, Item_2ee570 *y)
{
    for (Entry_2ee570 *e = begin; e != end; e++) {
        if ((e->a == x || e->b == x) && (e->a == y || e->b == y))
            return;
    }
    Maker_2ee570 maker;
    Entry_2ee570 *made = x->flag ? maker.FUN_002f8ef0(x, y) : maker.FUN_002f8ef0(y, x);
    if (end < limit) {
        Entry_2ee570 *slot = end;
        end = slot + 1;
        if (slot)
            *slot = *made;
    }
}
