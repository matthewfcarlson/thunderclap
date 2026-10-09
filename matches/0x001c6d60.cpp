struct Sub {
    void cleanup();
};
struct Item {
    char pad[4];
};
void __cdecl FUN_001c6d60(Item* a, Item* b) {
    for (; a != b; a = (Item*)((char*)a + 0xa8)) {
        if (a)
            ((Sub*)((char*)a + 4))->cleanup();
    }
}