// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000c6bc0 @ 0x000c6bc0
#include "decls/address.h"
#include "decls/data/game/global.h"
inline void *operator new(unsigned int, void *p) { return p; }

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p);
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}
namespace pure3d { class CompositeDrawable; }

struct Sub_c6bc0 {
    int FUN_002843a0(unsigned __int64 key);
    void FUN_002848b0(int id, int zero, int value);
};

struct Resource_c6bc0 {
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Sub_c6bc0 *v11();
};

struct Loader_c6bc0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Resource_c6bc0 *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned __int64 key);
};

void FUN_000c6bc0(const char *name, const char *sub, int value)
{
    Loader_c6bc0 *loader = (*(Loader_c6bc0**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Resource_c6bc0 *res = loader->v3(&caster, FUN_002672f0(name, 0, 0));
    if (res) {
        res->AddRef();
        int id = res->v11()->FUN_002843a0(FUN_0027b020(sub));
        res->v11()->FUN_002848b0(id, 0, value);
        res->Release();
    }
}
