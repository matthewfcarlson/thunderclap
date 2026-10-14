// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 15/18, incomplete)
// FUN_001e4190 @ 0x001e4190
struct Item {
    char pad0[0xc];
    float key;
    char pad10[4];
};

void __cdecl FUN_001de1f0(Item *dest, Item *first, Item *last, int a, int b);

// Insertion sort of [first, last) by ascending key.
void FUN_001e4190(Item *first, Item *last) {
    if (first == last) {
        return;
    }
    for (Item *cur = first + 1; cur != last; cur++) {
        Item *next = cur + 1;
        Item *pos;
        if (cur->key < first->key) {
            pos = first;
        } else {
            pos = cur;
            while (cur->key < (pos - 1)->key) {
                pos--;
            }
        }
        if (pos != cur && cur != next) {
            FUN_001de1f0(pos, cur, next, 0, 0);
        }
    }
}
