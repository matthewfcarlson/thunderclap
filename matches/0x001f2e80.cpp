struct Item_1f2e80 {
    char pad[0x6c];
    float f;
    char p[4];
    int n;
};
int Compare(Item_1f2e80** a, Item_1f2e80** b) {
    Item_1f2e80* x = *a;
    Item_1f2e80* y = *b;
    if (!x)
        return y != 0;
    if (!y)
        return -1;
    if (x->n < y->n)
        return -1;
    if (x->f < y->f)
        return -1;
    if (x->f > y->f)
        return 1;
    return 0;
}