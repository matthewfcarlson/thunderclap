// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002a15d0 @ 0x002a15d0
struct Item {
    virtual void FUN_00000000();
    virtual void FUN_00000004();
    Item* FUN_002a1140(unsigned int count);
};
void* __cdecl FUN_00263ea0(unsigned int bytes);
struct Holder {
    char pad0[0x2c];
    Item* item;
    char pad30[4];
    unsigned int count;
    void FUN_002a15d0(unsigned int newCount);
};
void Holder::FUN_002a15d0(unsigned int newCount) {
    if (newCount != count) {
        if (item) {
            item->FUN_00000004();
            item = 0;
        }
        if (newCount != 0) {
            Item* created = 0;
            void* memory = FUN_00263ea0(0x28);
            if (memory) created = ((Item*)memory)->FUN_002a1140(newCount);
            if (created) created->FUN_00000000();
            if (item) item->FUN_00000004();
            item = created;
        }
        count = newCount;
    }
}