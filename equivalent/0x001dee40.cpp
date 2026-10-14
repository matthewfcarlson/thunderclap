// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 12/16, incomplete)
// FUN_001dee40 @ 0x001dee40
struct Item_1dee40 {
    char pad0[8];
    int f8;
    int fc;
};

class Table_1dee40 {
public:
    char pad0[0x1e620];
    Item_1dee40 *items[0x200 / 4];
    int count;                  // 0x1e820

    Item_1dee40 *Get(int i) { return (i < count && i >= 0) ? items[i] : 0; }
    Item_1dee40 *FUN_001dee40(int a, int b);
};

Item_1dee40 *Table_1dee40::FUN_001dee40(int a, int b)
{
    for (int i = 0; i < count; i++) {
        Item_1dee40 *it = Get(i);
        if (it->f8 == a && it->fc == b)
            return Get(i);
    }
    return 0;
}
