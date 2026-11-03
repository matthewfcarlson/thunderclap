// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00142940 @ 0x00142940
#include "decls/address.h"
#include "gen/owners.h"
namespace pure3d { struct Animation_142940 {}; }
namespace content { namespace LoadInventory {
template<class T> struct DynamicCaster { virtual void cast(); };
}}
struct Inventory {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(content::LoadInventory::DynamicCaster<pure3d::Animation_142940>*, int, int);
};
struct Provider {  };
struct World { char pad[0x54]; struct Service* service; };
struct Service {  };
struct Pair { int first; int second; };
// equiv-conv: FUN_00142940 eax
extern "C" int FUN_00142940(void * pair) {
    int first = ((Pair *)pair)->first;
    int second = ((Pair *)pair)->second;
    if (!(first | second)) return 0;
    Provider* provider = ((Provider *)((owners::Target_862a0 *)(DAT_004dd700->service))->FUN_000862a0());
    Inventory* inventory = ((Inventory *)((owners::Target_203d70 *)provider)->FUN_00203d70());
    content::LoadInventory::DynamicCaster<pure3d::Animation_142940> caster;
    return inventory->slot3(&caster, first, second);
}