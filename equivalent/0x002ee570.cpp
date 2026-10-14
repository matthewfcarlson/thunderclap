// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 18/18)
// FUN_002ee570 @ 0x002ee570
struct Entry {
    void *a;
    void *b;
    int c, d, e;
};

struct Item {
    char pad00[0x50];
    unsigned char flag;
};

struct Maker {
    Entry data;
    Entry *FUN_002f8ef0(Item *x, Item *y);
};

class Graph {
public:
    char pad00[0x4c];
    Entry *begin;
    Entry *end;
    Entry *limit;
    void FUN_002ee570(Item *x, Item *y);
};

// Adds an edge between x and y unless one already connects them.
void Graph::FUN_002ee570(Item *x, Item *y)
{
    for (Entry *e = begin; e != end; e++) {
        if ((e->a == x || e->b == x) && (e->a == y || e->b == y))
            return;
    }
    Maker maker;
    Entry *made = x->flag ? maker.FUN_002f8ef0(x, y) : maker.FUN_002f8ef0(y, x);
    if (end < limit) {
        Entry *slot = end;
        end = slot + 1;
        if (slot)
            *slot = *made;
    }
}
