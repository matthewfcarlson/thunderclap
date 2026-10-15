// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 22/22)
// FEScreenBase::vfunc_23 @ 0x000e4fc0
// equiv-map: ??0FELayout@@QAE@PAVFEContainer@@PBD@Z = 0x000e1f10
// FEContainer::vfunc_23 (0x000e4a40); identical code is FEScreenBase::vfunc_23 (0x000e4fc0).
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
inline void* operator new(unsigned int, void* p) throw() { return p; }

struct Key { unsigned int lo; unsigned int hi; };
extern "C" Key __cdecl FUN_0027b020(const char* s);

class FEContainer;
class FEObject;

struct Owner {
    char pad0[0x1800];
    int v1800;
    int v1804;
    int v1808;
};

class FELayout {
public:
    FELayout(FEContainer* parent, const char* name) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void AttachObject(FEObject* obj);
    virtual bool IsPrimary();
    virtual void f20();
    char pad04[4];
    FEContainer* parent;
    char pad0c[4];
    unsigned int keyLo;
    unsigned int keyHi;
    char pad18[0x38 - 0x18];
    int sizeInfo;
    char pad3c[4];
};

class SingleLayout : public FELayout {
public:
    SingleLayout(FEContainer* p, const char* n) throw() : FELayout(p, n) { field44 = 0; mLayout = 0; }
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    FELayout* mLayout;
    int field44;
};

class FEObject {
public:
    char pad0[0x14];
    FELayout* layout;
    char pad18[0x6c - 0x18];
    int f6c;
    int f70;
    char pad74[0xa8 - 0x74];
    Owner* ownerRef;
};

class FEContainer {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void AddLayout(FELayout* layout);
    virtual void vfunc_22();
    virtual FEObject* vfunc_23(FEObject* obj, const char* name);

    Owner* owner;
    char pad08[0x48 - 0x08];
    FELayout* primary;
    FELayout* layouts[0x80];
    char pad24c[0x200];
    FEObject* children[0x80];
};

FEObject* FEContainer::vfunc_23(FEObject* obj, const char* name)
{
    if (obj == 0)
        return 0;

    FELayout* layout = 0;
    for (int i = 0; i < 0x80; i++) {
        FELayout* l = layouts[i];
        if (l == 0)
            break;
        Key key = FUN_0027b020(name);
        if (key.lo == l->keyLo && key.hi == l->keyHi) {
            layout = layouts[i];
            break;
        }
    }

    if (layout == 0) {
        void* mem = FUN_0008d690(0x48);
        if (mem)
            layout = new (mem) SingleLayout(this, name);
        AddLayout(layout);
    }

    layout->sizeInfo = owner->v1800;
    obj->layout = layout;
    obj->ownerRef = (Owner*)layout->parent->owner;

    for (int j = 0; j < 0x80; j++) {
        if (children[j] == 0) {
            children[j] = obj;
            break;
        }
    }

    obj->f6c = owner->v1804;
    obj->f70 = owner->v1808;
    layout->AttachObject(obj);
    if (primary == 0 && layout->IsPrimary())
        primary = layout;
    return obj;
}
