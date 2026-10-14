// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000c6c40 @ 0x000c6c40
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

struct Index {
    int FUN_0027b200(unsigned __int64 key);
};

struct Info {
    char pad00[8];
    Index *index;
};

struct Entry {
    int unused;
    int key;
    int value;
};

struct EntryList {
    char pad00[0x3c];
    Entry *begin;
    Entry *end;
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
    virtual Info *v11();
    char pad04[0x40];
    EntryList *list;
};

struct Loader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Resource *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned __int64 key);
};
extern Loader *DAT_004dd9cc;

extern void __cdecl FUN_000c6a90(int found, int value);

void FUN_000c6c40(const char *name, const char *key, int value)
{
    Loader *loader = DAT_004dd9cc;
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Resource *res = loader->v3(&caster, FUN_002672f0(name, 0, 0));
    if (res) {
        res->AddRef();
        Index *index = res->v11()->index;
        int id = index->FUN_0027b200(FUN_0027b020(key));
        EntryList *list = res->list;
        int found = 0;
        for (int i = 0; i < (unsigned char)(list->end - list->begin); i++) {
            Entry *e = &list->begin[(unsigned char)i];
            if (e->key == id) {
                found = e->value;
                break;
            }
        }
        FUN_000c6a90(found, value);
        res->Release();
    }
}
