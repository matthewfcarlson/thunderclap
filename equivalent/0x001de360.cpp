// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001de360 @ 0x001de360
#include "compat/ptr.h"
struct Sub_1de360 {
    virtual void v0();
    virtual void v1();
};
struct Item_1de360 {
    int pad0;
    Sub_1de360 sub;
    Item_1de360 *FUN_001db1c0(int arg);
};
void *FUN_0008d690(hulk_uintptr size);

struct Owner_1de360 {
    char pad[0x1e824];
    Item_1de360 *current;
    char pad1e828[8];
    int arg;
    char pad1e834[0x1ec40 - 0x1e834];
    int z0, z1, z2, z3;
    void FUN_001de360(int a);
};

void Owner_1de360::FUN_001de360(int a)
{
    Item_1de360 *raw = (Item_1de360 *)FUN_0008d690(0x10);
    Item_1de360 *item;
    if (raw)
        item = raw->FUN_001db1c0(a);
    else
        item = 0;
    if (item)
        item->sub.v0();
    if (current)
        current->sub.v1();
    current = item;
    arg = a;
    z0 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
}
