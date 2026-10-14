struct Entry_1b5800 {
    char bytes[24];
};
struct Sub_1b5800 {
    char pad[0x18];
    Entry_1b5800* entries;
    char pad2[4];
    unsigned short count;
};
struct Item_1b5800 {
    char pad[0x44];
    Sub_1b5800* sub;
};
struct Vec_1b5800 {
    Item_1b5800** begin;
    Item_1b5800** end;
    Entry_1b5800* Get(int id);
};
Entry_1b5800* Vec_1b5800::Get(int id) {
    if (id == -1)
        return 0;
    int hi = (id >> 16) & 0xffff;
    if (hi >= 0 && hi < end - begin) {
        Item_1b5800* p = begin[hi];
        if (p) {
            int lo = id & 0xffff;
            if (lo >= 0 && lo < p->sub->count)
                return &p->sub->entries[(unsigned short)lo];
        }
    }
    return 0;
}