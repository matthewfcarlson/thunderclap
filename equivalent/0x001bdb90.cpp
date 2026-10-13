// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 32/32)
// FUN_001bdb90 @ 0x001bdb90
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

class Res {
public:
    virtual void AddRef();
    virtual void Release();
};

class Composite : public Res {
public:
    void FUN_002998d0(int v);
};

class Inventory {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res *get(void *caster, unsigned __int64 key);
};

struct InvHolder {
    char pad0[0xaa0];
    Inventory *inv;
};

struct Flags {
    char pad0[0x32];
    char b32;
};

struct Holder {
    InvHolder *FUN_000862a0();
    Flags *FUN_00086290();
};

struct Manager {
    char pad0[0x54];
    Holder *holder;
};

extern Manager *DAT_004dd700;
extern const char *DAT_004c4bfc;
extern const char *DAT_004c4bf8;
extern const char *DAT_004c4bf4;
extern const char *DAT_004c4bf0;
extern const char *DAT_004c4bec;
extern const char *DAT_004c4be8;
extern "C" int __cdecl FUN_00266da0(int mode);
unsigned __int64 __cdecl FUN_002672f0(const char *s, int a, int b);

class Widget {
public:
    char pad0[4];
    Res *r4;
    Res *r8;
    Res *rc;
    Res *r10;
    Res *r14;
    Res *r18;
    void FUN_001bdb90();
};

void Widget::FUN_001bdb90()
{
    struct Frame {
        char caster[4];
        int saved;
    } f;

    f.saved = FUN_00266da0(0x11);
    Inventory *inv = DAT_004dd700->holder->FUN_000862a0()->inv;
    Res *r;

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bfc, 0, 0));
    if (r)
        r->AddRef();
    if (r4)
        r4->Release();
    r4 = r;
    if (r)
        ((Composite *)r)->FUN_002998d0(0);

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bf8, 0, 0));
    if (r)
        r->AddRef();
    if (r8)
        r8->Release();
    r8 = r;
    if (r)
        ((Composite *)r)->FUN_002998d0(0);

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bf4, 0, 0));
    if (r)
        r->AddRef();
    if (rc)
        rc->Release();
    rc = r;
    if (r)
        ((Composite *)r)->FUN_002998d0(0);

    r = inv->get(new (f.caster) content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable>, FUN_002672f0(DAT_004c4bf0, 0, 0));
    if (r)
        r->AddRef();
    if (r10)
        r10->Release();
    r10 = r;
    if (r)
        ((Composite *)r)->FUN_002998d0(0);

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
