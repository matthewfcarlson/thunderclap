// STATUS: equivalent (tools/equiv.py level 3: 383 inputs, branch coverage 6/6)
// FUN_00204180 @ 0x00204180
extern "C" int __cdecl FUN_00266da0(int pool);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);

struct Item_204180 {
    char data[0x56];
    void FUN_00208a90();
};

class ItemSet {
public:
    char pad0[0x58c];
    Item_204180* items;
    char pad1[8];
    int count;
    void FUN_00204180(int n);
};

void ItemSet::FUN_00204180(int n) {
    int savedPool = FUN_00266da0(0xb);
    int* block = (int*)FUN_0008d6d0(n * sizeof(Item_204180) + 4);
    Item_204180* arr;
    if (block) {
        *block = n;
        arr = (Item_204180*)(block + 1);
        Item_204180* p = arr;
        for (int i = n; i > 0; i--) {
            p->FUN_00208a90();
            p++;
        }
    } else {
        arr = 0;
    }
    items = arr;
    count = n;
    FUN_00266da0(savedPool);
}
