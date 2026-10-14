struct Entry_1b57a0 {
    char bytes[24];
};
struct Item_1b57a0 {
    char pad[0x18];
    Entry_1b57a0* entries;
    char pad2[4];
    unsigned short count;
};
struct Obj_1b57a0 {
    char pad[0x44];
    Item_1b57a0* item;
};
class Manager_1b57a0 {
  public:
    Obj_1b57a0** begin;
    Obj_1b57a0** end;
    Entry_1b57a0* Get(int id);
};
Entry_1b57a0* Manager_1b57a0::Get(int id) {
    if (id == -1)
        return 0;
    int hi = (id >> 16) & 0xffff;
    if (hi >= 0 && hi < end - begin) {
        Obj_1b57a0* p = begin[hi];
        if (p) {
            int lo = id & 0xffff;
            if (lo >= 0) {
                Item_1b57a0* item = p->item;
                if (lo < item->count)
                    return &item->entries[(unsigned short)lo];
            }
        }
    }
    return 0;
}