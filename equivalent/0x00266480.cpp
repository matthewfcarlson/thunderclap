// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_00266480 @ 0x00266480
class Pool_266480 {
  public:
    void FUN_00231550(unsigned int size, int a, int b);
    void FUN_00231690();
    char pad0[8];
    unsigned int used;
    char flag;
    char pad1[3];
    unsigned int limit;
    char pad2[0x24 - 0x14];
};
void* __cdecl FUN_0008d690(unsigned int size);
unsigned int __cdecl FUN_00356c30(unsigned int n);

namespace content {
class LoadInventory {
  public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    LoadInventory(unsigned int capacity);
    int field4;
    char flag8;
    char flag9;
    char pad[2];
    Pool_266480* pool;
    int field10;
};
}

content::LoadInventory::LoadInventory(unsigned int capacity) {
    field4 = 0;
    flag8 = 1;
    flag9 = 1;
    Pool_266480* p = (Pool_266480*)FUN_0008d690(0x24);
    if (p != 0) {
        if (capacity == 0 || (capacity & (capacity - 1)) != 0)
            capacity = 1u << (FUN_00356c30(capacity) + 1);
        p->FUN_00231550(capacity, 0x50, 0x64);
    }
    pool = p;
    p->flag = flag8;
    if (flag8 && p->limit < p->used)
        p->FUN_00231690();
    field10 = 0;
}
