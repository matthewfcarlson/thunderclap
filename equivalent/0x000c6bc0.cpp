// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000c6bc0 @ 0x000c6bc0
inline void *operator new(unsigned int, void *p) { return p; }
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
unsigned __int64 __cdecl FUN_0027b020(const char *name);

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

struct Sub {
    int FUN_002843a0(unsigned __int64 key);
    void FUN_002848b0(int id, int zero, int value);
};

struct Resource {
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
    virtual Sub *v11();
};

struct Loader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Resource *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned __int64 key);
};
extern Loader *DAT_004dd9cc;

void FUN_000c6bc0(const char *name, const char *sub, int value)
{
    Loader *loader = DAT_004dd9cc;
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Resource *res = loader->v3(&caster, FUN_002672f0(name, 0, 0));
    if (res) {
        res->AddRef();
        int id = res->v11()->FUN_002843a0(FUN_0027b020(sub));
        res->v11()->FUN_002848b0(id, 0, value);
        res->Release();
    }
}
