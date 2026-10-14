// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 21/22, incomplete)
// FUN_001f2f30 @ 0x001f2f30
struct Id64 { unsigned int lo; unsigned int hi; };
struct Item {
    char pad0[8];
    int id;
    char padc[4];
    Id64* key;
};
struct Group {
    char pad0[8];
    Item* items[32];
    int count;
    char pad8c[0xcc - 0x8c];
    Item* current;
    Item* FUN_001f2f30(int id, Id64* key);
};

Item* Group::FUN_001f2f30(int id, Id64* key) {
    if (current->id == id)
        return current;
    for (int i = 0; i < count; ++i) {
        Item* item = items[i];
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
