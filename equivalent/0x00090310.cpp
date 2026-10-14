// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_00090310 @ 0x00090310
struct Slot {
    int threshold;
    char name[0x40];
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
