// STATUS: equivalent (tools/equiv.py level 3: 1751 inputs, branch coverage 2/2)
// FUN_00067ea0 @ 0x00067ea0
struct Key_67ea0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

struct Entry_67ea0 {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    char pad14[4];
    Key_67ea0 key;
};

class Table_67ea0 {
public:
    int one;
    int zero;
    char pad08[0x100];
    Entry_67ea0 entries[0x40];
    Table_67ea0();
    void FUN_00067a40();
};

Table_67ea0::Table_67ea0()
{
    one = 1;
    zero = 0;
    for (int i = 0; i < 0x40; i++) {
        Entry_67ea0 *e = &entries[i];
        e->key.FUN_0027af00();
        e->key.FUN_0027b040("");
        e->f00 = 0;
        e->f0c = 0;
        e->f08 = 0;
        e->f04 = 0;
        e->f10 = 0;
        e->key.FUN_0027b040("");
    }
    FUN_00067a40();
}
