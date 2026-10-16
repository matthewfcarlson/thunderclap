// STATUS: equivalent (tools/equiv.py level 3: 233 inputs, branch coverage 12/12)
// fight::ParamValueInventoryEntity::vfunc_9 @ 0x00235760
#include "decls/data/engine/fight.h"

struct Item;
struct Entity;

struct Registry_235760 {
    char pad0[0xc];
    void *container;        // 0xc
};

struct Iter_235760 {
    void *container;
    int index;
    Registry_235760 *owner;
    void FUN_002314a0(void *container);
    Item *FUN_00231640();
    Item *FUN_002314c0();
};


namespace fight {
class ParamValueInventoryEntity {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
    virtual bool Accepts(Entity *owner, Item *item);        // vfunc_6
    virtual void vfunc_7(); virtual void vfunc_8();
    virtual int vfunc_9(Entity *owner, Item *wanted);
};

// Returns the 1-based position of `wanted` among the items this value accepts, or 0.
int ParamValueInventoryEntity::vfunc_9(Entity *owner, Item *wanted)
{
    if (wanted == 0)
        return 0;
    Registry_235760 *reg = (*(Registry_235760**)&DAT_004e5bb8);
    if (reg == 0)
        return 0;

    int pos = 1;
    Iter_235760 it;
    it.FUN_002314a0(reg->container);
    it.owner = reg;
    for (Item *item = it.FUN_00231640(); item != 0; item = it.FUN_002314c0()) {
        if (Accepts(owner, item)) {
            if (item == wanted)
                return pos;
            pos++;
        }
    }
    return 0;
}
}
