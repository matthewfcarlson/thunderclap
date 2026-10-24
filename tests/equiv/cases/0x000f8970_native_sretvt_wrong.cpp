// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// FUN_000f8970 @ 0x000f8970
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

class Ref_f8970 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Loader_f8970 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref_f8970 *v3(content::LoadInventory::DynamicCaster<pure3d::Font> *caster, unsigned int lo, unsigned int hi);
};


struct Id64_f8970 {
    unsigned int lo;
    unsigned int hi;
};

Id64_f8970 __cdecl FUN_0027b020(const char *name);

class FontSet_f8970 {
public:
    char pad0[0x24];
    Ref_f8970 *fonts[0x24 / 4];
    Id64_f8970 ids[(0x88 - 0x48) / 8];
    int count;

    void FUN_000f8970(const char *name);
};

void FontSet_f8970::FUN_000f8970(const char *name)
{
    int i = count;
    if (fonts[i] != 0)
        fonts[i]->Release();
    Id64_f8970 id = FUN_0027b020(name);
    ids[i] = id;
    content::LoadInventory::DynamicCaster<pure3d::Font> caster;
    Ref_f8970 *r = (*(Loader_f8970**)&DAT_004dd9c8)->v3(&caster, id.lo, id.hi);
    fonts[i] = r;
    r->Release();
    count = count + 1;
}
