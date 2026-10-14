// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// FUN_000f8970 @ 0x000f8970
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

class Ref {
public:
    virtual void AddRef();
    virtual void Release();
};

class Loader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Ref *v3(content::LoadInventory::DynamicCaster<pure3d::Font> *caster, unsigned int lo, unsigned int hi);
};

extern Loader *DAT_004dd9c8;

struct Id64 {
    unsigned int lo;
    unsigned int hi;
};

Id64 __cdecl FUN_0027b020(const char *name);

class FontSet {
public:
    char pad0[0x24];
    Ref *fonts[0x24 / 4];
    Id64 ids[(0x88 - 0x48) / 8];
    int count;

    void FUN_000f8970(const char *name);
};

void FontSet::FUN_000f8970(const char *name)
{
    int i = count;
    if (fonts[i] != 0)
        fonts[i]->Release();
    Id64 id = FUN_0027b020(name);
    ids[i] = id;
    content::LoadInventory::DynamicCaster<pure3d::Font> caster;
    Ref *r = DAT_004dd9c8->v3(&caster, id.lo, id.hi);
    fonts[i] = r;
    r->AddRef();
    count = count + 1;
}
