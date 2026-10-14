// STATUS: equivalent (tools/equiv.py level 3: 132 inputs, branch coverage 7/8, incomplete)
// FUN_0021a960 @ 0x0021a960
// FUN_0021a960: serialise a table through a writer callback (Writer arrives in esi)
// equiv-conv: FUN_0021a960 esi stack
struct Writer_21a960 {
    void *ctx;
    void (__cdecl *write)(void *ctx, void *data, int size, int arg);
    int arg;
};

struct Item_21a960 {
    char pad00[0xc];
    int length;
    char data[1];
};

struct Table_21a960 {
    char pad00[0x1c];
    Item_21a960 **items;
    char pad20[4];
    int count;
};

void FUN_0021a960(Writer_21a960 *w, Table_21a960 *t)
{
    int count = t->count;
    int len = count;
    w->write(w->ctx, &len, 4, w->arg);
    for (int i = 0; i < count; i++) {
        Item_21a960 *it = t->items[i];
        if (it != 0) {
            int n = it->length + 1;
            len = n;
            w->write(w->ctx, &len, 4, w->arg);
            w->write(w->ctx, it->data, n, w->arg);
        } else {
            len = 0;
            w->write(w->ctx, &len, 4, w->arg);
        }
    }
}
