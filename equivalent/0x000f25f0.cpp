// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000f25f0 @ 0x000f25f0
// FEBillboardAnimation constructor: look the billboard object up by name when the name is short enough.
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
namespace pure3d { class BillboardObject; }

extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

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
    virtual Ref *v3(content::LoadInventory::DynamicCaster<pure3d::BillboardObject> *caster, unsigned int lo, unsigned int hi);
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

class FEBillboardAnimation : public FEBase {
public:
    FEBillboardAnimation(int a, const char *name);
    virtual void v0();
};

FEBillboardAnimation::FEBillboardAnimation(int a, const char *name) : FEBase(a, name)
{
    unsigned int cookie = DAT_004d9968;
    const char *start = name + 1;
    const char *end = name;
    while (*end++) {
    }
    unsigned int length = end - start;
    if (length <= 0xfb) {
        Loader *ld = DAT_004dd9cc;
        Id64 id = FUN_0027b020(name);
        content::LoadInventory::DynamicCaster<pure3d::BillboardObject> caster;
        Ref *r = ld->v3(&caster, id.lo, id.hi);
        if (r != 0) {
            p0c = 0;
        }
    }
    __security_check_cookie(cookie);
}
