struct Result {
    unsigned int x, y, z;
};
struct Item {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void FUN_001fd7d0_slot8(Result* out);
};
unsigned __int64 __cdecl FUN_0027b020(unsigned int value);
struct Owner {
    Item* FUN_001fc8c0(unsigned __int64 key);
    Result* FUN_001fd7d0(Result* out, unsigned int value);
};
Result* Owner::FUN_001fd7d0(Result* out, unsigned int value) {
    unsigned __int64 key = FUN_0027b020(value);
    Item* item = FUN_001fc8c0(key);
    if (!item) {
        out->x = 0;
        out->y = 0;
        out->z = 0;
        return out;
    }
    Result result;
    item->FUN_001fd7d0_slot8(&result);
    *out = result;
    return out;
}