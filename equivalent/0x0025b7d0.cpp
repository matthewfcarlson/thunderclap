// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 8/8)
// FUN_0025b7d0 @ 0x0025b7d0
#include "decls/data/platform/xbox/audio.h"

struct Item_25b7d0 {
    char d[12];
    void FUN_00240060();
};

struct Link_25b7d0 {
    Link_25b7d0 *left;
};

struct Node : Link_25b7d0 {
    char pad4[0xc];
    Item_25b7d0 items[12];
};

struct Tree_25b7d0 {
    Link_25b7d0 *first;
    Link_25b7d0 head;
};

void __cdecl FUN_0025b5b0(Tree_25b7d0 *t, Node *n);
void __cdecl FUN_00247550(void *pool, Node *n);

void __cdecl FUN_0025b7d0(Tree_25b7d0 *t)
{
    while (t->first != &t->head) {
        Link_25b7d0 *l = t->first;
        while (l->left != &t->head)
            l = l->left;
        Node *n = (Node *)l;
        FUN_0025b5b0(t, n);
        for (int i = 11; i >= 0; i--)
            n->items[i].FUN_00240060();
        FUN_00247550(((char*)((char*)&DAT_004e76e8 + 144)), n);
    }
}
