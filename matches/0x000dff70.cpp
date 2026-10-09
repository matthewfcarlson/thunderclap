struct Item {
    char pad[0x5c];
    unsigned char flag;
};
struct Container {
    char pad[8];
    Item* slots[32];
    void Clear();
};
void Container::Clear() {
    int count = 8;
    Item** p = slots + 1;
    do {
        Item* a = p[-1];
        if (a)
            a->flag = 0;
        Item* b = p[0];
        if (b)
            b->flag = 0;
        Item* c = p[1];
        if (c)
            c->flag = 0;
        Item* d = p[2];
        if (d)
            d->flag = 0;
        p += 4;
        --count;
    } while (count);
}