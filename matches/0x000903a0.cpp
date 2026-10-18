// FUN_000903a0 @ 0x000903a0
struct Slot_903a0 {
    int threshold;
    char pad[0x20];
    char name[0x20];
};
struct Table_903a0 {
    char pad[0xc8c];
    Slot_903a0 slot[16];
    const char* Find(int value);
};
const char* Table_903a0::Find(int value) {
    int found = -1;
    for (int i = 0; i < 16; i++) {
        if (slot[i].name[0] && value >= slot[i].threshold)
            found = i;
    }
    if (found == -1) return "none";
    return slot[found].name;
}
