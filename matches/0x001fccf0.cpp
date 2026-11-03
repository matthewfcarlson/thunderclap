#include "gen/owners.h"
struct Vector {
    unsigned int x, y, z;
};
struct Filter_1fccf0 {
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
struct Item_1fccf0 {
    char pad[0x114];
    int excluded;
    bool FUN_001d7300();
    Vector* FUN_001d6b40();
};
struct Collection_1fccf0 {
    int FUN_001dcf50();
};
struct Owner_1fccf0 {
    char pad[12];
    Collection_1fccf0* collection;
};
struct CTriggerVolumeManager_1fccf0 {
    char pad0[4];
    Owner_1fccf0* owner;
    char pad1[0x230];
    int count;
    Item_1fccf0* results[1];
    Filter_1fccf0* FUN_001fc7f0(unsigned int arg);
    void FUN_001fccf0(unsigned int arg, unsigned char active);
};
void CTriggerVolumeManager_1fccf0::FUN_001fccf0(unsigned int arg, unsigned char active) {
    Filter_1fccf0* filter = FUN_001fc7f0(arg);
    if (!filter)
        return;
    count = 0;
    Collection_1fccf0* collection = owner->collection;
    int n = collection->FUN_001dcf50();
    for (int i = n - 1; i >= 0; --i) {
        Item_1fccf0* item = ((Item_1fccf0 *)((owners::CGrabAction_1dc0b0 *)collection)->FUN_001dc0b0(i));
        ((owners::C_1d72e0 *)item)->FUN_001d72e0();
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
