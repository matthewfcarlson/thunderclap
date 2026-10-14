// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001c4190 @ 0x001c4190
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace pure3d { class DrawableHierarchy; }

struct Key {
    unsigned int lo;
    unsigned int hi;
};

class Res {
public:
    virtual void AddRef();
    virtual void Release();
};

class Inventory;
struct Holder44 {
    Inventory *FUN_00203d70();
};

class Inventory {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Res *get(void *caster, unsigned int lo, unsigned int hi);
};

struct Holder {
    Holder44 *FUN_000862a0();
};

struct Manager {
    char pad0[0x54];
    Holder *holder;
};

struct Entry;

struct Registry {
    void FUN_001c5ae0(Entry *e);
};

struct Entry {
    char pad0[0xc];
    Res *res;
    Entry *FUN_001c5cf0(Key *key, Res *r);
};

extern Manager *DAT_004dd700;
extern "C" int __cdecl FUN_00266da0(int mode);
void *__cdecl FUN_0008d690(unsigned int size);

class Loader {
public:
    char pad0[0xc];
    Registry *registry;
    void FUN_001c4190(Key *key);
};

void Loader::FUN_001c4190(Key *key)
{
    int saved = FUN_00266da0(0xf);
    Inventory *inv = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
    Res *res = inv->get(&caster, key->lo, key->hi);
    if (res) {
        Entry *e = (Entry *)FUN_0008d690(0x10);
        if (e)
            e = e->FUN_001c5cf0(key, res);
        if (e->res)
            e->res->Release();
        e->res = 0;
        registry->FUN_001c5ae0(e);
    }
    FUN_00266da0(saved);
}
