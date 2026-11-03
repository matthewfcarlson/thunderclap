// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 0/0)
// FUN_000f6b50 @ 0x000f6b50
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
typedef unsigned __int64 Key_f6b50;

namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }
namespace pure3d { class CompositeDrawable_f6b50; }

struct Frag;

struct Sub_f6b50 {
    Frag* FUN_002843a0(Key_f6b50 key);
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

extern "C" void FUN_000f6b50(const char* nameA, const char* nameB, int value)
{
    Inventory_f6b50* inv = (*(Inventory_f6b50**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_f6b50> caster;
    Loaded_f6b50* loaded = inv->find(&caster, FUN_002672f0(nameA, 0, 0));
    loaded->l0();
    Sub_f6b50* sub = loaded->l11();
    Frag* frag = sub->FUN_002843a0(FUN_002672f0(nameB, 0, 0));
    ((owners::Obj_2848b0 *)(loaded->l11()))->FUN_002848b0((hulk_intptr)(Frag *)frag, 0, (int *)(hulk_uintptr)(int)value);
    loaded->l1();
}
