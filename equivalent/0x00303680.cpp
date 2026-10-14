// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 15/18, incomplete)
// FUN_00303680 @ 0x00303680
struct Item {
    char pad0[0x24];
    float key;
    char pad28[0x44 - 0x28];
};

void __cdecl FUN_00303080(Item *dest, Item *first, Item *last, int a, int b);

// Insertion sort of [first, last) by ascending key.
void FUN_00303680(Item *first, Item *last) {
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
            FUN_00303080(pos, cur, next, 0, 0);
        }
    }
}
