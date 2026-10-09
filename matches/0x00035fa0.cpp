typedef unsigned char u8;
struct Item {
    char pad[0x74];
    void* sub;
};
struct Slot {
    Item* Get();
};
struct Sub {
    char pad[0x72];
    u8 value;
};
struct Entry {
    Slot* slot;
    char pad[0x4c];
};
struct Obj {
    char pad[0x3a8];
    Entry entries[8];
    void Set(u8);
};
void Obj::Set(u8 value) {
    for (int i = 0; i < 8; ++i) {
        Slot* s = entries[i].slot;
        if (s) {
            Item* p = s->Get();
            if (p && p->sub)
                ((Sub*)p->sub)->value = value;
        }
    }
}