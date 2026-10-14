// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f6b50 @ 0x000f6b50
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char*, int, int);

namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
namespace pure3d { class CompositeDrawable; }

struct Frag;

struct Sub {
    Frag* FUN_002843a0(Key key);
    void FUN_002848b0(Frag* frag, int zero, int value);
};

struct Loaded {
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
    virtual void l8();
    virtual void l9();
    virtual void l10();
    virtual Sub* l11();
};

struct Inventory {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded* find(void* caster, Key key);
};
extern Inventory* DAT_004dd9cc;

void FUN_000f6b50(const char* nameA, const char* nameB, int value)
{
    Inventory* inv = DAT_004dd9cc;
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Loaded* loaded = inv->find(&caster, FUN_002672f0(nameA, 0, 0));
    loaded->l0();
    Sub* sub = loaded->l11();
    Frag* frag = sub->FUN_002843a0(FUN_002672f0(nameB, 0, 0));
    loaded->l11()->FUN_002848b0(frag, 0, value);
    loaded->l1();
}
