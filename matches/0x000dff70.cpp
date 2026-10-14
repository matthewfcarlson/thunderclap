struct Item_dff70 {
    char pad[0x5c];
    unsigned char flag;
};
struct Container_dff70 {
    char pad[8];
    Item_dff70* slots[32];
    void Clear();
};
void Container_dff70::Clear() {
    int count = 8;
    Item_dff70** p = slots + 1;
    do {
        Item_dff70* a = p[-1];
        if (a)
            a->flag = 0;
        Item_dff70* b = p[0];
        if (b)
            b->flag = 0;
        Item_dff70* c = p[1];
        if (c)
            c->flag = 0;
        Item_dff70* d = p[2];
        if (d)
            d->flag = 0;
        p += 4;
        --count;
    } while (count);
}