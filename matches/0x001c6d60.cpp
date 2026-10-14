struct Sub_1c6d60 {
    void cleanup();
};
struct Item_1c6d60 {
    char pad[4];
};
void __cdecl FUN_001c6d60(Item_1c6d60* a, Item_1c6d60* b) {
    for (; a != b; a = (Item_1c6d60*)((char*)a + 0xa8)) {
        if (a)
            ((Sub_1c6d60*)((char*)a + 4))->cleanup();
    }
}