// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00142940 @ 0x00142940
#include "decls/address.h"
namespace pure3d { struct Animation {}; }
namespace content { namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void cast(); };
}}
struct Inventory {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(content::LoadInventory::DynamicCaster<pure3d::Animation>*, int, int);
};
struct Provider { Inventory* FUN_00203d70(); };
struct World { char pad[0x54]; struct Service* service; };
struct Service { Provider* FUN_000862a0(); };
struct Pair { int first; int second; };
// equiv-conv: FUN_00142940 eax
int FUN_00142940(Pair* pair) {
    int first = pair->first;
    int second = pair->second;
    if (!(first | second)) return 0;
    Provider* provider = DAT_004dd700->service->FUN_000862a0();
    Inventory* inventory = provider->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
    return inventory->slot3(&caster, first, second);
}