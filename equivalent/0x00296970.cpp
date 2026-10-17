// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00296970 @ 0x00296970
struct Owner;
struct Item {
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    void FUN_002a77c0(Owner *owner);
};
struct Owner {
    char pad[0xa8];
    Item *item;
    void FUN_00296970(Item *replacement);
};
void Owner::FUN_00296970(Item *replacement) {
    if (replacement) replacement->FUN_00000000();
    if (item) item->FUN_00000004();
    item = replacement;
    if (replacement) replacement->FUN_002a77c0(this);
}