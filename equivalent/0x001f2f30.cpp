// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 21/22, incomplete)
// FUN_001f2f30 @ 0x001f2f30
struct Id64_1f2f30 { unsigned int lo; unsigned int hi; };
struct Item_1f2f30 {
    char pad0[8];
    int id;
    char padc[4];
    Id64_1f2f30* key;
};
struct Group_1f2f30 {
    char pad0[8];
    Item_1f2f30* items[32];
    int count;
    char pad8c[0xcc - 0x8c];
    Item_1f2f30* current;
    Item_1f2f30* FUN_001f2f30(int id, Id64_1f2f30* key);
};

Item_1f2f30* Group_1f2f30::FUN_001f2f30(int id, Id64_1f2f30* key) {
    if (current->id == id)
        return current;
    for (int i = 0; i < count; ++i) {
        Item_1f2f30* item = items[i];
        if (item->id != id)
            continue;
        if (key == 0 || (key->lo | key->hi) == 0) {
            if (item->key == 0)
                return items[i];
        }
        if (key != 0 && item->key != 0 && item->key->lo == key->lo && item->key->hi == key->hi)
            return items[i];
    }
    return 0;
}
