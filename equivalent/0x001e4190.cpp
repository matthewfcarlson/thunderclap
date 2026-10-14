// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 15/18, incomplete)
// FUN_001e4190 @ 0x001e4190
struct Item_1e4190 {
    char pad0[0xc];
    float key;
    char pad10[4];
};

void __cdecl FUN_001de1f0(Item_1e4190 *dest, Item_1e4190 *first, Item_1e4190 *last, int a, int b);

// Insertion sort of [first, last) by ascending key.
void FUN_001e4190(Item_1e4190 *first, Item_1e4190 *last) {
    if (first == last) {
        return;
    }
    for (Item_1e4190 *cur = first + 1; cur != last; cur++) {
        Item_1e4190 *next = cur + 1;
        Item_1e4190 *pos;
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
