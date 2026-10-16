// STATUS: equivalent (tools/equiv.py level 3: 2167 inputs, branch coverage 4/4)
// FUN_000f89e0 @ 0x000f89e0
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

namespace pure3d { class Font; }

class Ref_f89e0 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Loader_f89e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f89e0 *v3(content::LoadInventory::DynamicCaster<pure3d::Font> *caster, unsigned int lo, unsigned int hi);
};


struct Id64_f89e0 {
    unsigned int lo;
    unsigned int hi;
};

class FontSet_f89e0 {
public:
    char pad0[0x24];
    Ref_f89e0 *fonts[0x24 / 4];
    Id64_f89e0 ids[(0x88 - 0x48) / 8];
    int count;

    void FUN_000f89e0();
};

void __fastcall FUN_000f89e0(FontSet_f89e0 *set)
{
    for (int i = 0; i < set->count; i++) {
        content::LoadInventory::DynamicCaster<pure3d::Font> caster;
        Ref_f89e0 *r = (*(Loader_f89e0**)&DAT_004dd9c8)->v3(&caster, set->ids[i].lo, set->ids[i].hi);
        set->fonts[i] = r;
        r->AddRef();
    }
}
