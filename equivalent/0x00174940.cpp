// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 22/22)
// hulkfight::motion::PushOutAction::vfunc_5 @ 0x00174940
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const V3 *in, V3 *out);
    void FUN_0022c3b0(const V3 *in, V3 *out);
};

struct Table {
    char pad0[0x1c];
    Matrix *mats;
};

struct Layers {
    char pad0[0x64];
    Table *table;
};

struct Wrap {
    char pad0[0x124];
    void *f124;
};

struct Entity {
    char pad0[0x334];
    void *f334;
    void *f338;
    bool FUN_00038de0(V3 *from, V3 *to, int a, int flag, V3 *hit, V3 *normal, int b, int c);
    void FUN_00035760(V3 *push);
};

struct Handle {
    Entity *FUN_00059a30();
    Layers *FUN_00059a40();
};

struct Owner {
    Handle *FUN_000592a0();
};

struct World {
    char pad0[0x20];
    Wrap *wrap;
};
extern World *DAT_004dd700;

bool __cdecl FUN_00018960(float a, float b, float eps);

struct Data {
    char pad0[0x20];
    V3 pa;              // 0x20
    V3 pb;              // 0x2c
    float f38;
    float f3c;
    char b40;
};

namespace hulkfight {
namespace motion {

class PushOutAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a1, int a2);
    char pad04[0x18];
    Data *data;         // 0x1c
    Owner *owner;       // 0x20
    int index;          // 0x24
};

bool PushOutAction::vfunc_5(int a1, int a2)
{
    if (a1 != 0)
        return true;
    Handle *y = owner->FUN_000592a0();
    if (y == 0)
        return false;
    Entity *x = y->FUN_00059a30();
    if (x == 0)
        return false;
    Layers *layers = y->FUN_00059a40();
    if (layers == 0)
        return false;
    Matrix *mats = layers->table->mats;
    struct Frame {
        V3 t;
        float f38;
        V3 c;
        V3 p;
        V3 b;
        float rem;
        V3 hit;
        V3 normal;
        Matrix m;
    } f;
    int idx = index;
    f.p.x = 0;
    f.p.y = 0;
    f.p.z = 0;
    f.b.x = 0;
    f.b.y = 0;
    f.b.z = -1.0f;
    f.c.x = 0;
    f.c.y = 0;
    f.c.z = 0;
    f.m = mats[idx];
    f.t = data->pa;
    f.m.FUN_0022c2b0(&f.t, &f.p);
    f.t = data->pb;
    f.m.FUN_0022c3b0(&f.t, &f.b);
    f.b.FUN_0022d110();
    f.c = f.b;
    f.f38 = data->f38;
    double bx = f.b.x * f.f38;
    double by = f.b.y * f.f38;
    f.c.z = f.b.z * f.f38;
    World *w = DAT_004dd700;
    int flag = 0;
    void *cur = w->wrap->f124;
    if (cur != (void *)x && x->f338 != cur && x->f334 != cur)
        flag = 1;
    f.c.x = (float)(bx + f.p.x);
    f.c.y = (float)(by + f.p.y);
    f.c.z = f.c.z + f.p.z;
    if (!x->FUN_00038de0(&f.p, &f.c, 0, flag, &f.hit, &f.normal, 0, 0))
        return true;
    f.t = f.hit;
    f.t.x = f.t.x - f.p.x;
    f.t.y = f.t.y - f.p.y;
    f.t.z = f.t.z - f.p.z;
    f.rem = f.f38 - f.t.FUN_00018990();
    if (!(f.rem > 0.0f))
        return true;
    float ratio;
    if (FUN_00018960(f.f38, 0.0f, 0.00001f))
        ratio = 1.0f;
    else
        ratio = f.rem / f.f38;
    f.t = f.normal;
    Data *d = data;
    double k = ratio * d->f3c;
    f.t.x = (float)(f.t.x * k);
    f.t.y = (float)(f.t.y * k);
    f.t.z = (float)(f.t.z * k);
    if (d->b40 == 0)
        f.t.y = 0;
    x->FUN_00035760(&f.t);
    return true;
}

}
}
