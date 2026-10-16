// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/8, incomplete)
// FUN_000f2f50 @ 0x000f2f50
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

namespace pure3d { namespace scenegraph { class Scenegraph; } }

class Ref_f2f50 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Loader_f2f50 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f2f50 *v3(content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> *caster, unsigned int lo, unsigned int hi);
};


struct Id64_f2f50 {
    unsigned int lo;
    unsigned int hi;
};

Id64_f2f50 __cdecl FUN_0027b020(const char *name);

class Inventory_f2f50 {
public:
    char pad0[0x9a4];
    Ref_f2f50 *items[1];

    void FUN_000f2f50(const char *name);
};

void Inventory_f2f50::FUN_000f2f50(const char *name)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (items[i] == 0)
            break;
    }
    if (i < 1) {
        Loader_f2f50 *ld = (*(Loader_f2f50**)&DAT_004dd9cc);
        Id64_f2f50 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::scenegraph::Scenegraph> caster;
        Ref_f2f50 *r = ld->v3(&caster, id.lo, id.hi);
        items[i] = r;
        if (r != 0)
            r->AddRef();
    }
}
