// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 16/16)
// hulkfight::motion::WorldDamageAction::vfunc_5 @ 0x00143b20
extern float DAT_00412ec0;
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3 *other, float eps);
};
extern V3 DAT_004ad7b4;

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const V3 *in, V3 *out);
};

struct Skeleton {
    char pad0[0x1c];
    Matrix *mats;
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Entity {
    char pad0[0x120];
    Skeleton *skel;
    void FUN_00035160(Matrix *out);
    void FUN_00035630(V3 *in, V3 *out);
    float FUN_000354c0();
};

struct Anchor {
    void FUN_00059a50(V3 *out);
};

struct Handle {
    Entity *FUN_00059a30();
};

struct Caster {
    bool FUN_00202460(V3 *origin, V3 *dir, float len, int mask, V3 *hit, V3 *normal, void **ptr1, void **ptr2);
};
struct Sweeper {
    void FUN_001f6cd0(void *p1, void *p2, V3 *hit, V3 *normal, V3 *dir, int n, int a, int b, int *outv, int z);
};
struct Sink {
    void FUN_001ecd00(int v, Entity *e);
};
struct World {
    char pad0[0x24];
    Caster *caster;     // 0x24
    char pad28[0xc];
    Sink *sink;         // 0x34
    Sweeper *sweeper;   // 0x38
};
extern World *DAT_004dd700;

struct Owner {
    Handle *FUN_000592a0();
};

struct Data {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
    V3 posA;            // 0x18
    V3 vecB;            // 0x24
    float length;       // 0x30
    int count;          // 0x34
    int f38;
    int f3c;
};

void __cdecl FUN_00224d70(float angle, V3 *v);

class WorldDamageAction {
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
};

bool WorldDamageAction::vfunc_5(int a1, int a2)
{
    if (a1 != 1)
        return true;
    struct Frame {
        int outv;
        V3 out14;
        V3 vb;
        V3 pa;
        void *ptr1;
        void *ptr2;
        int n;
        int d3c;
        int d38;
        V3 w2;
        V3 w1;
        V3 hit;
        V3 normal;
        Matrix m;
    } f;
    f.n = data->count;
    if (f.n <= 0)
        return false;
    Handle *y = owner->FUN_000592a0();
    Handle *yy = y;
    Entity *x = y->FUN_00059a30();
    Skeleton *skel = x->skel;
    unsigned int idx = skel->FUN_002843a0(data->idLo, data->idHi);
    if (idx == 0xffff)
        x->FUN_00035160(&f.m);
    else
        f.m = skel->mats[idx];
    f.pa = data->posA;
    f.m.FUN_0022c2b0(&f.pa, &f.w1);
    f.vb = data->vecB;
    if (f.vb.z * f.vb.z + f.vb.y * f.vb.y + f.vb.x * f.vb.x <= DAT_00412ec0) {
        f.vb.x = 0;
        f.vb.y = 1.0f;
        f.vb.z = 0;
    }
    x->FUN_00035630(&f.vb, &f.out14);
    ((Anchor *)yy)->FUN_00059a50(&f.w2);
    f.out14.x = f.out14.x - f.w2.x;
    f.out14.y = f.out14.y - f.w2.y;
    f.out14.z = f.out14.z - f.w2.z;
    f.out14.FUN_0022d110();
    Data *d = data;
    f.d3c = d->f3c;
    f.ptr1 = 0;
    f.ptr2 = 0;
    f.outv = *(int *)&d->length;
    f.d38 = d->f38;
    if (!DAT_004dd700->caster->FUN_00202460(&f.w1, &f.out14, d->length, 1, &f.hit, &f.normal, &f.ptr1, &f.ptr2))
        return true;
    if (f.ptr1 == 0)
        return true;
    int n1 = f.n - 1;
    f.pa.x = 0;
    f.pa.y = -1.0f;
    f.pa.z = 0;
    bool vertical = f.out14.FUN_0022d2b0(&f.pa, 0.00001f);
    if (!vertical) {
        f.pa.x = 0;
        f.pa.y = 1.0f;
        f.pa.z = 0;
        vertical = f.out14.FUN_0022d2b0(&f.pa, 0.00001f);
    }
    if (vertical) {
        f.out14 = DAT_004ad7b4;
        FUN_00224d70(x->FUN_000354c0(), &f.out14);
    }
    f.outv = 0;
    DAT_004dd700->sweeper->FUN_001f6cd0(f.ptr1, f.ptr2, &f.hit, &f.normal, &f.out14, n1, f.d38, f.d3c, &f.outv, 0);
    DAT_004dd700->sink->FUN_001ecd00(f.outv, x);
    return true;
}
