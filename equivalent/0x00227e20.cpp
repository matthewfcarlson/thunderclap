// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 15/18, incomplete)
// FUN_00227e20 @ 0x00227e20
struct Item_227e20 {
    int pad0;
    float key;
    int pad8;
};

void __cdecl FUN_002264b0(Item_227e20 *dest, Item_227e20 *first, Item_227e20 *last, int a, int b);

// Insertion sort of [first, last) by descending key.
void FUN_00227e20(Item_227e20 *first, Item_227e20 *last) {
    if (first == last) {
        return;
    }
    for (Item_227e20 *cur = first + 1; cur != last; cur++) {
        Item_227e20 *next = cur + 1;
        Item_227e20 *pos;
        if (cur->key > first->key) {
            pos = first;
        } else {
            pos = cur;
            while (cur->key > (pos - 1)->key) {
                pos--;
            }
        }
        if (pos != cur && cur != next) {
            FUN_002264b0(pos, cur, next, 0, 0);
        }
    }
}
