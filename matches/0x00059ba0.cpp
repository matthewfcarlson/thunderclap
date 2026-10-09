struct Item {
    int key;
    char pad[0x20];
};
class C {
  public:
    char pad0[4];
    unsigned int count;
    Item* items;
    char* flags;
    Item* Find(int key);
};
Item* C::Find(int key) {
    unsigned int i;
    for (i = 0; i < count; ++i) {
        if (flags[i] != 0 && items[i].key == key)
            return items + i;
    }
    return 0;
}
