// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 8/8)
// FUN_0025b7d0 @ 0x0025b7d0
struct Item {
    char d[12];
    void FUN_00240060();
};

struct Link {
    Link *left;
};

struct Node : Link {
    char pad4[0xc];
    Item items[12];
};

struct Tree {
    Link *first;
    Link head;
};

void __cdecl FUN_0025b5b0(Tree *t, Node *n);
void __cdecl FUN_00247550(void *pool, Node *n);
extern char DAT_004e7778[];

void __cdecl FUN_0025b7d0(Tree *t)
{
    while (t->first != &t->head) {
        Link *l = t->first;
        while (l->left != &t->head)
            l = l->left;
        Node *n = (Node *)l;
        FUN_0025b5b0(t, n);
        for (int i = 11; i >= 0; i--)
            n->items[i].FUN_00240060();
        FUN_00247550(DAT_004e7778, n);
    }
}
