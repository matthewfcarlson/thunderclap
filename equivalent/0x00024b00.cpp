// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 10/10)
// FUN_00024b00 @ 0x00024b00
struct Name_24b00 {
    char pad0[8];
    char c8;
    char c9;
    char padA[2];
    bool FUN_0027af90(const Name_24b00* other);
};
struct Item_24b00 { char pad[0x22b8]; Name_24b00 name; };
struct Registry_24b00 { Item_24b00* FUN_00059c10(int id); };
struct Owner_24b00 { char pad[0x44]; Registry_24b00* registry; };

struct Group_24b00 {
    Owner_24b00* owner;
    char pad4[8];
    int count;
    int ids[16];
    int FUN_00024b00(const Name_24b00* key);
};

int Group_24b00::FUN_00024b00(const Name_24b00* key) {
    int matches = 0;
    for (int i = 0; i < count; ++i) {
        Name_24b00* n = &owner->registry->FUN_00059c10(ids[i])->name;
        if (n->FUN_0027af90(key) && n->c8 == key->c8 && n->c9 == key->c9)
            matches++;
    }
    return matches;
}
