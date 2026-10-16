// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0008d3a0 @ 0x0008d3a0
#include "decls/data/game/unknown.h"

struct Obj_8d3a0 {
    virtual void vfn0();
    virtual void vfn1();
};

struct HeapDesc {
    const char *name;
    int base;
    int size;
};

Obj_8d3a0 *FUN_0026cf20(int addr, int a, const char *name);
void FUN_002670b0(int idx, int a, Obj_8d3a0 *obj);

class Holder_8d3a0 {
public:
    void FUN_0008d3a0(int idx, int arg);
    int pad0;
    Obj_8d3a0 *slots[1];
};

void Holder_8d3a0::FUN_0008d3a0(int idx, int arg)
{
    Obj_8d3a0 *obj = FUN_0026cf20(((HeapDesc*)&DAT_00400520)[idx].base + ((HeapDesc*)&DAT_00400520)[idx].size, arg, ((HeapDesc*)&DAT_00400520)[idx].name);
    if (obj)
        obj->vfn0();
    if (slots[idx])
        slots[idx]->vfn1();
    slots[idx] = obj;
    FUN_002670b0(idx, arg, obj);
}
