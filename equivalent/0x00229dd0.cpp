// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 15/18, incomplete)
// FUN_00229dd0 @ 0x00229dd0
struct Item_229dd0 {
    int pad0;
    float key;
    int pad8;
};

void __cdecl FUN_00228990(Item_229dd0 *dest, Item_229dd0 *first, Item_229dd0 *last, int a, int b);

// Insertion sort of [first, last) by descending key.
void FUN_00229dd0(Item_229dd0 *first, Item_229dd0 *last) {
    if (first == last) {
        return;
    }
    for (Item_229dd0 *cur = first + 1; cur != last; cur++) {
        Item_229dd0 *next = cur + 1;
        Item_229dd0 *pos;
        if (cur->key > first->key) {
            pos = first;
        } else {
            pos = cur;
            while (cur->key > (pos - 1)->key) {
                pos--;
            }
        }
        if (pos != cur && cur != next) {
            FUN_00228990(pos, cur, next, 0, 0);
        }
    }
}
