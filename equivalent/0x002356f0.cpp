// STATUS: equivalent (tools/equiv.py level 3: 221 inputs, branch coverage 8/8)
// fight::ParamValueInventoryEntity::vfunc_8 @ 0x002356f0
struct Manager { char pad00[0xc]; void* list; };
struct Item;
struct Iter {
    void* list;
    int index;
    Manager* owner;
    void FUN_002314a0(void* list);
    Item* FUN_00231640();
    Item* FUN_002314c0();
};
extern Manager* DAT_004e5bb8;

class ParamValueInventoryEntity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool v6(int param, Item* item);
    virtual void v7();
    virtual int v8(int param);
};

int ParamValueInventoryEntity::v8(int param)
{
    Manager* mgr = DAT_004e5bb8;
    if (mgr == 0)
        return 0;
    int count = 1;
    Iter it;
    it.FUN_002314a0(mgr->list);
    it.owner = mgr;
    Item* item = it.FUN_00231640();
    while (item != 0) {
        if (v6(param, item))
            count++;
        item = it.FUN_002314c0();
    }
    return count;
}
