// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000f6b50 @ 0x000f6b50
#include "decls/address.h"
typedef unsigned __int64 Key_f6b50;

namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
namespace pure3d { class CompositeDrawable; }

struct Frag;

struct Sub_f6b50 {
    Frag* FUN_002843a0(Key_f6b50 key);
    void FUN_002848b0(Frag* frag, int zero, int value);
};

struct Loaded_f6b50 {
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
    virtual Sub_f6b50* l11();
};

struct Inventory_f6b50 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_f6b50* find(void* caster, Key_f6b50 key);
};
extern Inventory_f6b50* DAT_004dd9cc;

void FUN_000f6b50(const char* nameA, const char* nameB, int value)
{
    Inventory_f6b50* inv = DAT_004dd9cc;
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Loaded_f6b50* loaded = inv->find(&caster, FUN_002672f0(nameA, 0, 0));
    loaded->l0();
    Sub_f6b50* sub = loaded->l11();
    Frag* frag = sub->FUN_002843a0(FUN_002672f0(nameB, 0, 0));
    loaded->l11()->FUN_002848b0(frag, 0, value);
    loaded->l1();
}
