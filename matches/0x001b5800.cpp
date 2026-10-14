struct Entry {
    char bytes[24];
};
struct Sub {
    char pad[0x18];
    Entry* entries;
    char pad2[4];
    unsigned short count;
};
struct Item {
    char pad[0x44];
    Sub* sub;
};
struct Vec {
    Item** begin;
    Item** end;
    Entry* Get(int id);
};
Entry* Vec::Get(int id) {
    if (id == -1)
        return 0;
    int hi = (id >> 16) & 0xffff;
    if (hi >= 0 && hi < end - begin) {
        Item* p = begin[hi];
        if (p) {
            int lo = id & 0xffff;
            if (lo >= 0 && lo < p->sub->count)
                return &p->sub->entries[(unsigned short)lo];
        }
    }
    return 0;
}