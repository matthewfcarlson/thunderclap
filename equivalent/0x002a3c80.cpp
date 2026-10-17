// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002a3c80 @ 0x002a3c80
struct Owner;
struct Item {
    virtual void FUN_00000000();
    virtual void FUN_00000001();
    virtual void FUN_00000002();
    virtual void FUN_00000003();
    virtual void FUN_00000004();
    virtual void FUN_00000005(Owner *);
};
struct Owner {
    char pad[0xa4];
    Item *item;
    void FUN_002a3c80(Item *next);
};
void Owner::FUN_002a3c80(Item *next) {
    if (next) next->FUN_00000000();
    if (item) item->FUN_00000001();
    item = next;
    if (next) next->FUN_00000005(this);
}