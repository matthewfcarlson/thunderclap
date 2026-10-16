// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 7/8, incomplete)
// FUN_000f2ee0 @ 0x000f2ee0
#include "decls/data/game/global.h"

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d { class LightGroup; }

class Ref_f2ee0 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Loader_f2ee0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2ee0 *v3(content::LoadInventory::DynamicCaster<pure3d::LightGroup> *caster, unsigned int lo, unsigned int hi);
};


struct Id64_f2ee0 {
    unsigned int lo;
    unsigned int hi;
};

Id64_f2ee0 __cdecl FUN_0027b020(const char *name);

class Inventory_f2ee0 {
public:
    char pad0[0x994];
    Ref_f2ee0 *items[4];

    void FUN_000f2ee0(const char *name);
};

void Inventory_f2ee0::FUN_000f2ee0(const char *name)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (items[i] == 0)
            break;
    }
    if (i < 4) {
        Loader_f2ee0 *ld = (*(Loader_f2ee0**)&DAT_004dd9cc);
        Id64_f2ee0 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::LightGroup> caster;
        Ref_f2ee0 *r = ld->v3(&caster, id.lo, id.hi);
        items[i] = r;
        if (r != 0)
            r->AddRef();
    }
}
