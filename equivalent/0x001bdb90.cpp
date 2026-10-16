// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 32/32)
// FUN_001bdb90 @ 0x001bdb90
#include "decls/address.h"
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

extern const char *DAT_004c4bfc;
extern const char *DAT_004c4bf8;
extern const char *DAT_004c4bf4;
extern const char *DAT_004c4bf0;
extern const char *DAT_004c4bec;
extern const char *DAT_004c4be8;
extern "C" int __cdecl FUN_00266da0(int mode);

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

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bfc, 0, 0));
    if (r)
        r->AddRef();
    if (r4)
        r4->Release();
    r4 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bf8, 0, 0));
    if (r)
        r->AddRef();
    if (r8)
        r8->Release();
    r8 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bf4, 0, 0));
    if (r)
        r->AddRef();
    if (rc)
        rc->Release();
    rc = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bf0, 0, 0));
    if (r)
        r->AddRef();
    if (r10)
        r10->Release();
    r10 = r;
    if (r)
        ((Composite_1bdb90 *)r)->FUN_002998d0(0);

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bec, 0, 0));
    if (r)
        r->AddRef();
    if (r14)
        r14->Release();
    r14 = r;

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::Locator>, FUN_002672f0(DAT_004c4be8, 0, 0));
    if (r)
        r->AddRef();
    if (r18)
        r18->Release();
    r18 = r;

    DAT_004dd700->holder->FUN_00086290()->b32 = 0;
    FUN_00266da0(f.saved);
}
