// STATUS: equivalent (tools/equiv.py level 3: 630 inputs, branch coverage 8/8)
// FUN_001dd090 @ 0x001dd090
// 0x001dd090: push a three word value into the control block of every registered item
struct Block {
    char pad[0x1b8];
    int v0;
    int v1;
    int v2;
    char flag;
};

struct Item;
struct Info {
    char pad[0x70];
    Block* block;
};

struct Item {
    Info* FUN_001d72e0();
};

class Registry {
public:
    char pad[0x1e620];
    Item* items[0x80];
    int count;
    void FUN_001dd090(int a, int b, int c);
};

void Registry::FUN_001dd090(int a, int b, int c)
{
    for (int i = 0; i < count; i++) {
        Item* it = items[i];
        if (it->FUN_001d72e0() != 0 && it->FUN_001d72e0()->block != 0) {
            Block* blk = it->FUN_001d72e0()->block;
            blk->v0 = a;
            blk->v1 = b;
            blk->v2 = c;
            blk->flag = 1;
        }
    }
}
