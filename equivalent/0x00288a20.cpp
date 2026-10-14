// STATUS: equivalent (tools/equiv.py level 3: 2560 inputs, branch coverage 19/20, incomplete)
// FUN_00288a20 @ 0x00288a20
struct Item_288a20 {
    char pad0[0x10];
    int key;                // 0x10
};

class ItemList_288a20 {
public:
    char pad0[0x24];
    int sorted;             // 0x24
    int count;              // 0x28
    Item_288a20 **items;           // 0x2c
    Item_288a20 *FUN_00288a20(int key);
};

Item_288a20 *ItemList_288a20::FUN_00288a20(int key)
{
    int n = count;
    if (n <= 0)
        return 0;

    if (sorted == 1) {
        int hi = n - 1;
        int lo = 0;
        int mid = hi / 2;
        if (hi > 0) {
            Item_288a20 **arr = items;
            do {
                int v = arr[mid]->key;
                if (v > key) {
                    hi = mid - 1;
                } else if (v < key) {
                    lo = mid + 1;
                } else {
                    return arr[mid];
                }
                mid = (hi - lo) / 2 + lo;
            } while (lo < hi);
        }
        Item_288a20 *it = items[mid];
        if (it->key == key)
            return it;
        return 0;
    }

    Item_288a20 **arr = items;
    for (int i = 0; i < n; i++) {
        if (arr[i]->key == key)
            return arr[i];
    }
    return 0;
}
