// STATUS: equivalent (tools/equiv.py level 3: 623 inputs, branch coverage 10/12, incomplete)
// FUN_00024a10 @ 0x00024a10
struct Head { char pad[0xb4]; };
struct NodeB { char data[0x28]; void FUN_00232240(); };
struct NodeA { char data[0x20]; void FUN_00232240(); };
struct Item : public Head, public NodeB, public NodeA {
    void FUN_00037000();
};
struct Registry { Item* FUN_00059c10(int id); };
struct Owner { char pad[0x44]; Registry* registry; };
struct Inner { char pad[0x124]; Item* current; };
struct Game { char pad[0x20]; Inner* inner; };
extern Game* DAT_004dd700;

struct Group {
    Owner* owner;
    char pad4[8];
    int count;
    int ids[16];
    bool FUN_00024a10();
};

bool Group::FUN_00024a10() {
    Item* keep = DAT_004dd700->inner->current;
    for (int i = 0; i < count; ++i) {
        Item* item = owner->registry->FUN_00059c10(ids[i]);
        if (item && item != keep) {
            static_cast<NodeA*>(item)->FUN_00232240();
            static_cast<NodeB*>(item)->FUN_00232240();
            item->FUN_00037000();
        }
    }
    return true;
}
