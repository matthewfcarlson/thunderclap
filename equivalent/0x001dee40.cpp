// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 12/16, incomplete)
// FUN_001dee40 @ 0x001dee40
struct Item {
    char pad0[8];
    int f8;
    int fc;
};

class Table {
public:
    char pad0[0x1e620];
    Item *items[0x200 / 4];
    int count;                  // 0x1e820

    Item *Get(int i) { return (i < count && i >= 0) ? items[i] : 0; }
    Item *FUN_001dee40(int a, int b);
};

Item *Table::FUN_001dee40(int a, int b)
{
    for (int i = 0; i < count; i++) {
        Item *it = Get(i);
        if (it->f8 == a && it->fc == b)
            return Get(i);
    }
    return 0;
}
