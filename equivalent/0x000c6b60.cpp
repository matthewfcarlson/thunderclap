// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 2/2)
// FUN_000c6b60 @ 0x000c6b60
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

struct Sub;

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

struct Result {
    Sub *sub;
    int pad4;
    unsigned __int64 key;
};

void FUN_000c6b60(const char *name, const char *subName, Result *out)
{
    Loader *loader = DAT_004dd9cc;
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    // the original loads the loader's vptr before FUN_002672f0 and the slot after it
    typedef Resource *(__fastcall *V3Fn)(Loader*, int, content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *, unsigned __int64);
    void **vtable = *(void ***)loader;
    unsigned __int64 id64 = FUN_002672f0(name, 0, 0);
    Resource *res = ((V3Fn)vtable[3])(loader, 0, &caster, id64);
    if (res) {
        out->sub = res->v11();
        out->key = FUN_0027b020(subName);
    }
}
