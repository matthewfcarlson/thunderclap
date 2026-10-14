typedef unsigned char u8_35fa0;
struct Item_35fa0 {
    char pad[0x74];
    void* sub;
};
struct Slot_35fa0 {
    Item_35fa0* Get();
};
struct Sub_35fa0 {
    char pad[0x72];
    u8_35fa0 value;
};
struct Entry_35fa0 {
    Slot_35fa0* slot;
    char pad[0x4c];
};
struct Obj_35fa0 {
    char pad[0x3a8];
    Entry_35fa0 entries[8];
    void Set(u8_35fa0);
};
void Obj_35fa0::Set(u8_35fa0 value) {
    for (int i = 0; i < 8; ++i) {
        Slot_35fa0* s = entries[i].slot;
        if (s) {
            Item_35fa0* p = s->Get();
            if (p && p->sub)
                ((Sub_35fa0*)p->sub)->value = value;
        }
    }
}