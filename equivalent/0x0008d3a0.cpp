// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 4/4)
// FUN_0008d3a0 @ 0x0008d3a0
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"

struct Obj_8d3a0 {
    virtual void vfn0();
    virtual void vfn1();
};

struct HeapDesc {
    const char *name;
    int base;
    int size;
};   // the heap table 0x00400520

extern "C" Obj_8d3a0 *FUN_0026cf20(int addr, int a, const char *name);
void FUN_002670b0(int idx, int a, Obj_8d3a0 *obj);

class Holder_8d3a0 : public HeapSet {
public:
    void FUN_0008d3a0(int idx, int arg);
};

void Holder_8d3a0::FUN_0008d3a0(int idx, int arg)
{
    Obj_8d3a0 *obj = FUN_0026cf20(((HeapDesc*)&DAT_00400520)[idx].base + ((HeapDesc*)&DAT_00400520)[idx].size, arg, ((HeapDesc*)&DAT_00400520)[idx].name);
    if (obj)
        obj->vfn0();
    if (heaps[idx])
        ((Obj_8d3a0 *)heaps[idx])->vfn1();
    heaps[idx] = obj;
    FUN_002670b0(idx, arg, obj);
}
