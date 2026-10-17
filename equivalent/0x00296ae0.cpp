// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00296ae0 @ 0x00296ae0
struct Owner;
struct Item {
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    void FUN_002a7cf0(Owner* owner);
};
struct Owner {
    char pad[0x2c];
    Item* item;
    void FUN_00296ae0(Item* value);
};
void Owner::FUN_00296ae0(Item* value) {
    if (value) value->FUN_00000000();
    if (item) item->FUN_00000004();
    item = value;
    if (value) value->FUN_002a7cf0(this);
}