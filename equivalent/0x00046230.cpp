// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 7/8, incomplete)
// FUN_00046230 @ 0x00046230
struct Item { virtual void slot0(); virtual void release(); };
struct Container { char pad[12]; int count; Item **items; unsigned char FUN_00046230(); };
unsigned char Container::FUN_00046230() {
    for (int i = count - 1; i >= 0; --i) {
        Item **slot = &items[i];
        Item *item = *slot;
        if (item) {
            item->release();
            *slot = 0;
        }
    }
    count = 0;
    return 1;
}