// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 16/16)
// FUN_00059db0 @ 0x00059db0
struct Res_59db0 {
    void FUN_0003b620(int v);
    void FUN_00263e90();
};

class Handle_59db0 {
public:
    virtual void v0();
    virtual void Release();
    void FUN_00222b90(int v);
};

struct Item_59db0 {
    char pad0[0x10];
    Res_59db0 *res;           // 0x10
    char pad14[4];
    Handle_59db0 *handle;     // 0x18
    char pad1c[8];
};

struct Current_59db0 {
    char pad0[0x124];
    Res_59db0 *res;           // 0x124
};

struct Manager_59db0 {
    char pad0[0x20];
    Current_59db0 *current;   // 0x20
};

extern Manager_59db0 *DAT_004dd700;

class ItemList_59db0 {
public:
    char pad0[4];
    unsigned int count;         // 4
    Item_59db0 *items;                // 8
    unsigned char *active;      // 0xc
    void FUN_00059db0();
};

void ItemList_59db0::FUN_00059db0()
{
    for (unsigned int i = 0; i < count; i++) {
        if (active[i] == 0)
            continue;
        Item_59db0 *item = &items[i];
        if (item->res != 0 && item->res == DAT_004dd700->current->res)
            continue;
        if (item->res != 0) {
            item->res->FUN_0003b620(0);
            item->res->FUN_00263e90();
            item->res = 0;
        }
        if (item->handle != 0) {
            item->handle->FUN_00222b90(1);
            if (item->handle != 0) {
                item->handle->Release();
                item->handle = 0;
            }
        }
        active[i] = 0;
    }
}
