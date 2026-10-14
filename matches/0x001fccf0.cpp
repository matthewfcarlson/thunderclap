struct Vector {
    unsigned int x, y, z;
};
struct Filter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual bool test(Vector v);
};
struct Item {
    char pad[0x114];
    int excluded;
    void FUN_001d72e0();
    bool FUN_001d7300();
    Vector* FUN_001d6b40();
};
struct Collection {
    int FUN_001dcf50();
    Item* FUN_001dc0b0(int index);
};
struct Owner {
    char pad[12];
    Collection* collection;
};
struct Target {
    char pad0[4];
    Owner* owner;
    char pad1[0x230];
    int count;
    Item* results[1];
    Filter* FUN_001fc7f0(unsigned int arg);
    void FUN_001fccf0(unsigned int arg, unsigned char active);
};
void Target::FUN_001fccf0(unsigned int arg, unsigned char active) {
    Filter* filter = FUN_001fc7f0(arg);
    if (!filter)
        return;
    count = 0;
    Collection* collection = owner->collection;
    int n = collection->FUN_001dcf50();
    for (int i = n - 1; i >= 0; --i) {
        Item* item = collection->FUN_001dc0b0(i);
        item->FUN_001d72e0();
        if (active && !item->FUN_001d7300())
            continue;
        if (item->excluded)
            continue;
        Vector* v = item->FUN_001d6b40();
        if (filter->test(*v)) {
            results[count] = item;
            ++count;
        }
    }
}
