// STATUS: equivalent (tools/equiv.py level 3: 93 inputs, branch coverage 20/20)
// hulkfight::motion::ImpulseVelocityAction::vfunc_5 @ 0x00190a40
struct V3 {
    float x, y, z;
    bool FUN_0022d2b0(const V3 *other, float eps);
};

struct Mat {
    float m[16];
    void FUN_0022c2b0(const V3 *in, V3 *out);
    void FUN_0022c3b0(const V3 *in, V3 *out);
};

float __cdecl FUN_000186b0(float *v, float *lo, float *hi);

struct Prop {
    char pad0[0x1e58];
    float scale;
};

struct Table {
    char pad0[0x10];
    unsigned int count;
    char pad14[0x10];
    unsigned int *ids;
    unsigned int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Skeleton {
    char pad0[8];
    Table *table;
    char pad0c[0x10];
    Mat *mats;
};

struct Holder {
    char pad0[0x120];
    Skeleton *skel;
    char pad124[0x210];
    Prop *propB;    // 0x334
    Prop *propA;    // 0x338
    void FUN_00038410(V3 *a, V3 *b);
};

struct Source {
    char pad0[8];
    V3 posA;
    char pad14[0x14];
    V3 velB;
    char pad34[0xc];
};

struct Params {
    char pad0[0x10];
    unsigned int idLo;
    unsigned int idHi;
    V3 anchor;      // 0x18
    V3 start;       // 0x24
    V3 end;         // 0x30
    char pad3c;
    char pad3d[3];
    float factor;   // 0x40
};

struct Handle {
    Holder *FUN_00059a30();
};

struct Owner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Source *GetSource();
    Handle *FUN_000592a0();
};

struct ArgBlock {
    char pad0[0x28];
    V3 vel;
};

class ImpulseVelocityAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, int b);
    char pad4[0x18];
    Params *params;
    Owner *owner;
};

bool ImpulseVelocityAction::vfunc_5(int a, int b)
{
    if (a != 0)
        return true;
    Holder *holder = owner->FUN_000592a0()->FUN_00059a30();
    Skeleton *skel = holder->skel;
    if (skel == 0)
        return false;
    unsigned int idx = 0;
    if ((params->idLo | params->idHi) != 0) {
        idx = skel->table->FUN_0027b200(params->idLo, params->idHi);
        if (idx == 0xffff)
            idx = 0;
    }
    Mat m = skel->mats[idx];
    V3 zero;
    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    V3 t1 = params->anchor;
    m.FUN_0022c2b0(&t1, &zero);
    V3 p = params->start;
    t1 = params->end;
    if (t1.z * t1.z + t1.y * t1.y + t1.x * t1.x > 0.0f) {
        float scale = 0;
        if (holder->propA != 0) {
            scale = holder->propA->scale;
        } else if (holder->propB != 0) {
            scale = holder->propB->scale;
        }
        t1.x = t1.x - p.x;
        t1.y = t1.y - p.y;
        float one = 1.0f;
        float lo = 0;
        t1.z = t1.z - p.z;
        float c = FUN_000186b0(&scale, &lo, &one);
        float dx = t1.x * c;
        t1.y = t1.y * c;
        t1.z = t1.z * c;
        p.x = p.x + dx;
        p.y = p.y + t1.y;
        p.z = p.z + t1.z;
    }
    V3 w;
    w.x = 0;
    w.y = 0;
    w.z = 0;
    m.FUN_0022c3b0(&p, &w);
    bool doSet = params->pad3c != 0;
    if (!doSet) {
        t1.x = 0;
        t1.y = 0;
        t1.z = 0;
        doSet = w.FUN_0022d2b0(&t1, 0.00001f);
    }
    if (doSet) {
        Source *src = owner->GetSource();
        if (src != 0) {
            zero = src->posA;
            w = ((ArgBlock *)src)->vel;
            float k = params->factor;
            w.x = w.x * k;
            w.y = w.y * k;
            w.z = w.z * k;
        }
    }
    holder->FUN_00038410(&zero, &w);
    return false;
}
