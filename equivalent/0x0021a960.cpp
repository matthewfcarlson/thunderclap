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

extern "C" void FUN_0021a960(void *w, void *t)
{
    int count = ((Table_21a960 *)t)->count;
    int len = count;
    ((Writer_21a960 *)w)->write(((Writer_21a960 *)w)->ctx, &len, 4, ((Writer_21a960 *)w)->arg);
    for (int i = 0; i < count; i++) {
        Item_21a960 *it = ((Table_21a960 *)t)->items[i];
        if (it != 0) {
            int n = it->length + 1;
            len = n;
            ((Writer_21a960 *)w)->write(((Writer_21a960 *)w)->ctx, &len, 4, ((Writer_21a960 *)w)->arg);
            ((Writer_21a960 *)w)->write(((Writer_21a960 *)w)->ctx, it->data, n, ((Writer_21a960 *)w)->arg);
        } else {
            len = 0;
            ((Writer_21a960 *)w)->write(((Writer_21a960 *)w)->ctx, &len, 4, ((Writer_21a960 *)w)->arg);
        }
    }
}
