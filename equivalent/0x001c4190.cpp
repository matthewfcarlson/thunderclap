// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001c4190 @ 0x001c4190
#include "compat/ptr.h"
#include "decls/address.h"
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d { class DrawableHierarchy; }

struct Key_1c4190 {
    unsigned int lo;
    unsigned int hi;
};

class Res_1c4190 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Inventory_1c4190;
struct Holder44_1c4190 {
    Inventory_1c4190 *FUN_00203d70();
};

class Inventory_1c4190 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res_1c4190 *get(void *caster, unsigned int lo, unsigned int hi);
};

struct Holder_1c4190 {
    Holder44_1c4190 *FUN_000862a0();
};

struct World {
    char pad0[0x54];
    Holder_1c4190 *holder;
};

struct Entry_1c4190;

struct Registry_1c4190 {
    void FUN_001c5ae0(Entry_1c4190 *e);
};

struct Entry_1c4190 {
    char pad0[0xc];
    Res_1c4190 *res;
    Entry_1c4190 *FUN_001c5cf0(Key_1c4190 *key, Res_1c4190 *r);
};

extern "C" int __cdecl FUN_00266da0(hulk_intptr mode);
void *__cdecl FUN_0008d690(hulk_uintptr size);

class Loader_1c4190 {
public:
    char pad0[0xc];
    Registry_1c4190 *registry;
    void FUN_001c4190(Key_1c4190 *key);
};

void Loader_1c4190::FUN_001c4190(Key_1c4190 *key)
{
    int saved = FUN_00266da0(0xf);
    Inventory_1c4190 *inv = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
    Res_1c4190 *res = inv->get(&caster, key->lo, key->hi);
    if (res) {
        Entry_1c4190 *e = (Entry_1c4190 *)FUN_0008d690(0x10);
        if (e)
            e = e->FUN_001c5cf0(key, res);
        if (e->res)
            e->res->Release();
        e->res = 0;
        registry->FUN_001c5ae0(e);
    }
    FUN_00266da0(saved);
}
