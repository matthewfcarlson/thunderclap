struct Item_59ba0 {
    int key;
    char pad[0x20];
};
class C_59ba0 {
  public:
    char pad0[4];
    unsigned int count;
    Item_59ba0* items;
    char* flags;
    Item_59ba0* Find(int key);
};
Item_59ba0* C_59ba0::Find(int key) {
    unsigned int i;
    for (i = 0; i < count; ++i) {
        if (flags[i] != 0 && items[i].key == key)
            return items + i;
    }
    return 0;
}
