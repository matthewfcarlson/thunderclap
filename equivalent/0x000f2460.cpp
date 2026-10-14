// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f2460 @ 0x000f2460
inline void *operator new(unsigned int, void *p) throw() { return p; }
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
namespace pure3d { class CompositeDrawable; }

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
    virtual Ref *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned int lo, unsigned int hi);
};
extern Loader *DAT_004dd9cc;
struct Id64 { unsigned int lo; unsigned int hi; };
Id64 __cdecl FUN_0027b020(const char *name);

// equiv-map: ??0FEBase@@QAE@HPBD@Z = 0x000e13c0
class FEBase {
public:
    FEBase(int a, const char *name);
    virtual void v0();
    char pad04[8];
    Ref *p0c;
    char pad10[0x50];
};

class FEPoseAnimation : public FEBase {
public:
    Ref *p60;
    FEPoseAnimation(int a, const char *name);
    virtual void v0();
};

FEPoseAnimation::FEPoseAnimation(int a, const char *name) : FEBase(a, name)
{
    p60 = 0;
    p0c = 0;
    Loader *ld = DAT_004dd9cc;
    Id64 id = FUN_0027b020(name);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    Ref *r = ld->v3(&caster, id.lo, id.hi);
    if (r != 0) {
        p60 = r;
        r->AddRef();
        p0c = p60;
        p60->AddRef();
    }
}
