// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// CMotionTrailAction::vfunc_6 @ 0x000235f0
inline void *operator new(unsigned int, void *p) { return p; }

struct Vec3 { int x, y, z; };

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

namespace pure3d { class Shader; }

struct Handle { char pad[4]; };

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Handle *f3(content::LoadInventory::DynamicCaster<pure3d::Shader> *caster, int a, int b);
};

struct Holder44 { Factory *FUN_00203d70(); };
struct Holder28 { Holder44 *FUN_000862a0(); };
struct Manager { char pad0[0x54]; Holder28 *holder; };
extern Manager *DAT_004dd700;

struct Owner { char pad[4]; };
Owner *__fastcall FUN_000592a0(void *x);

struct Registry {
    char pad[0x120];
    int value120;
    char pad124[0x1e04 - 0x124];
    int slots[16];
    int FUN_00036cb0(unsigned int i);
    void FUN_00036c90(unsigned int i, int v);
};
Registry *__fastcall FUN_00059a30(Owner *o);

struct Renderer {
    int FUN_00283d60(int a14, int a18, int e120, Handle *h, void *p30, void *p60, int a28, void *pa8, Vec3 vb0, Vec3 vbc);
    void FUN_002834e0(int v);
};
Renderer *__cdecl FUN_0027f250();

struct Data {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1c[0x20 - 0x1c];
    int f20;
    int f24;
    int f28;
    char pad2c[0x30 - 0x2c];
    char block30[0x30];
    char block60[0x48];
    char blocka8[8];
    Vec3 vb0;
    Vec3 vbc;
    char flagc8;
    char flagc9;
    char padca[2];
    int fcc;
};

class CMotionTrailAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int arg);
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad04[0x18];
    void *ownerRef;
    Data *data;
    int result;
};

char CMotionTrailAction::vfunc_6(int arg)
{
    Factory *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    content::LoadInventory::DynamicCaster<pure3d::Shader> caster;
    Handle *handle = factory->f3(&caster, data->f20, data->f24);
    Registry *reg = FUN_00059a30(FUN_000592a0(ownerRef));
    Renderer *renderer = FUN_0027f250();
    Data *d = data;
    result = renderer->FUN_00283d60(d->f14, d->f18, reg->value120, handle, d->block30, d->block60,
                                    d->f28, d->blocka8, d->vb0, d->vbc);
    if (data->flagc9) {
        renderer->FUN_002834e0(reg->FUN_00036cb0(data->fcc));
        reg->FUN_00036c90(data->fcc, result);
    }
    return data->flagc8;
}
