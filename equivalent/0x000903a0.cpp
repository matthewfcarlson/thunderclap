// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000903a0 @ 0x000903a0
struct Slot {
    int threshold;
    char pad[0x20];
    char name[0x20];
};
struct Table {
    char pad[0xc8c];
    Slot slot[16];
    const char* Find(int value);
};
const char* Table::Find(int value) {
    int found = -1;
    for (int i = 0; i < 16; i++) {
        if (slot[i].name[0] && value >= slot[i].threshold)
            found = i;
    }
    if (found == -1) return "none";
    return slot[found].name;
}
