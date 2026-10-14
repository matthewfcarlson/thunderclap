struct Entry {
    char bytes[24];
};
struct Item {
    char pad[0x18];
    Entry* entries;
    char pad2[4];
    unsigned short count;
};
struct Obj {
    char pad[0x44];
    Item* item;
};
class Manager {
  public:
    Obj** begin;
    Obj** end;
    Entry* Get(int id);
};
Entry* Manager::Get(int id) {
    if (id == -1)
        return 0;
    int hi = (id >> 16) & 0xffff;
    if (hi >= 0 && hi < end - begin) {
        Obj* p = begin[hi];
        if (p) {
            int lo = id & 0xffff;
            if (lo >= 0) {
                Item* item = p->item;
                if (lo < item->count)
                    return &item->entries[(unsigned short)lo];
            }
        }
    }
    return 0;
}