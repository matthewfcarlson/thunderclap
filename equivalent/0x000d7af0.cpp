// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000d7af0 @ 0x000d7af0
inline void *operator new(unsigned int, void *p) { return p; }
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

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
namespace pure3d { class DrawableHierarchy; }

struct Node {
    virtual void AddRef();
};

struct Loader_d7af0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node *v3(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *caster, unsigned __int64 key);
};
extern Loader_d7af0 *DAT_004dd9cc;

struct FUN_000e9240 {
    virtual void slot0();
    char pad04[0x13c];
    FUN_000e9240(int arg);
};

class FEBackground : public FUN_000e9240 {
public:
    virtual void slot0();
    char pad140;
    char flag141;
    char pad142[0xe];
    Node *drawable;
    FEBackground(int arg, const char *name);
};

FEBackground::FEBackground(int arg, const char *name) : FUN_000e9240(arg)
{
    drawable = 0;
    Loader_d7af0 *loader = DAT_004dd9cc;
    content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *caster =
        new (&arg) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
    drawable = loader->v3(caster, FUN_002672f0(name, 0, 0));
    if (drawable)
        drawable->AddRef();
    flag141 = 0;
}
