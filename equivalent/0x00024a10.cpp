// STATUS: equivalent (tools/equiv.py level 3: 623 inputs, branch coverage 10/12, incomplete)
// FUN_00024a10 @ 0x00024a10
struct Head_24a10 { char pad[0xb4]; };
struct NodeB_24a10 { char data[0x28]; void FUN_00232240(); };
struct NodeA_24a10 { char data[0x20]; void FUN_00232240(); };
struct Item_24a10 : public Head_24a10, public NodeB_24a10, public NodeA_24a10 {
    void FUN_00037000();
};
struct Registry_24a10 { Item_24a10* FUN_00059c10(int id); };
struct Owner_24a10 { char pad[0x44]; Registry_24a10* registry; };
struct Inner_24a10 { char pad[0x124]; Item_24a10* current; };
struct Game_24a10 { char pad[0x20]; Inner_24a10* inner; };
extern Game_24a10* DAT_004dd700;

struct Group_24a10 {
    Owner_24a10* owner;
    char pad4[8];
    int count;
    int ids[16];
    bool FUN_00024a10();
};

bool Group_24a10::FUN_00024a10() {
    Item_24a10* keep = DAT_004dd700->inner->current;
    for (int i = 0; i < count; ++i) {
        Item_24a10* item = owner->registry->FUN_00059c10(ids[i]);
        if (item && item != keep) {
            static_cast<NodeA_24a10*>(item)->FUN_00232240();
            static_cast<NodeB_24a10*>(item)->FUN_00232240();
            item->FUN_00037000();
        }
    }
    return true;
}
