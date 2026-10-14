// STATUS: equivalent (tools/equiv.py level 3: 599 inputs, branch coverage 10/10)
// FUN_00024b00 @ 0x00024b00
struct Name {
    char pad0[8];
    char c8;
    char c9;
    char padA[2];
    bool FUN_0027af90(const Name* other);
};
struct Item { char pad[0x22b8]; Name name; };
struct Registry { Item* FUN_00059c10(int id); };
struct Owner { char pad[0x44]; Registry* registry; };

struct Group {
    Owner* owner;
    char pad4[8];
    int count;
    int ids[16];
    int FUN_00024b00(const Name* key);
};

int Group::FUN_00024b00(const Name* key) {
    int matches = 0;
    for (int i = 0; i < count; ++i) {
        Name* n = &owner->registry->FUN_00059c10(ids[i])->name;
        if (n->FUN_0027af90(key) && n->c8 == key->c8 && n->c9 == key->c9)
            matches++;
    }
    return matches;
}
