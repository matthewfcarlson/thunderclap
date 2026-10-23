// STATUS: equivalent (tools/equiv.py level 3: 19957 inputs, branch coverage 32/32)
// FUN_001bdb90 @ 0x001bdb90
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d {
class CompositeDrawable;
class Locator;
}

class Res_1bdb90 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Composite_1bdb90 : public Res_1bdb90 {
public:
    void FUN_002998d0(int v);
};

class Inventory_1bdb90 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res_1bdb90 *get(void *caster, unsigned __int64 key);
};

struct InvHolder {
    char pad0[0xaa0];
    Inventory_1bdb90 *inv;
};

struct Flags_1bdb90 {
    char pad0[0x32];
    char b32;
};

struct Holder_1bdb90 {
    InvHolder *FUN_000862a0();
    Flags_1bdb90 *FUN_00086290();
};

struct World {
    char pad0[0x54];
    Holder_1bdb90 *holder;
};

extern "C" int __cdecl FUN_00266da0(hulk_intptr mode);

class Widget_1bdb90 {
public:
    char pad0[4];
    Res_1bdb90 *r4;
    Res_1bdb90 *r8;
    Res_1bdb90 *rc;
    Res_1bdb90 *r10;
    Res_1bdb90 *r14;
    Res_1bdb90 *r18;
    void FUN_001bdb90();
};

void Widget_1bdb90::FUN_001bdb90()
{
    struct Frame {
        char caster[4];
        int saved;
    } f;

    f.saved = FUN_00266da0(0x11);
    Inventory_1bdb90 *inv = DAT_004dd700->holder->FUN_000862a0()->inv;
    Res_1bdb90 *r;
    // the original loads the inventory's vptr before each key lookup and the slot after it
    typedef Res_1bdb90 *(__fastcall *GetFn)(Inventory_1bdb90 *, int, void *, unsigned __int64);
    void **vtable;
    void *caster;
    unsigned __int64 key;

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bfc), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r4)
        r4->Release();
    r4 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bf8), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r8)
        r8->Release();
    r8 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bf4), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (rc)
        rc->Release();
    rc = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bf0), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r10)
        r10->Release();
    r10 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>;
    key = FUN_002672f0((*(const char**)&DAT_004c4bec), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r14)
        r14->Release();
    r14 = r;

    vtable = *(void ***)inv;
    caster = new (f.caster) content::LoadInventory::DynamicCaster<pure3d::Locator>;
    key = FUN_002672f0((*(const char**)&DAT_004c4be8), 0, 0);
    r = ((GetFn)vtable[3])(inv, 0, caster, key);
    if (r)
        r->AddRef();
    if (r18)
        r18->Release();
    r18 = r;

    DAT_004dd700->holder->FUN_00086290()->b32 = 0;
    FUN_00266da0(f.saved);
}
