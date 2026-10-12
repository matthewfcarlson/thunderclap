// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 48/48)
// hulkfight::motion::FlyingAutoTargetAction::vfunc_5 @ 0x00135f90
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const V3 *other, float epsilon);
    void FUN_00011160(float s, V3 *d);
};

union FloatBits {
    float f;
    unsigned int u;
};

static float AbsF(float v)
{
    FloatBits b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

extern "C" float __cdecl FUN_00224f10(V3 *v);
extern "C" void __cdecl FUN_00224d70(float angle, V3 *v);
extern "C" float __cdecl FUN_00224ea0(float x, float z);
extern "C" float __cdecl FUN_00224fc0(float a, float b);

class Target {
public:
    virtual void v0();
    virtual void v1();
    char pad04[4];
    struct Mesh *mesh;
    int kind;
    char pad10[0x40 - 0x10];
    V3 pos;
};

struct Mesh {
    char pad0[0x11c];
    struct Info *info;
    char pad120[0x140 - 0x120];
    int type;
};

struct Info {
    char pad0[0x30];
    float height;
};

struct Stats {
    char pad0[0x328];
    Target *target;
    char pad32c[0x2064 - 0x32c];
    V3 aim2064;
    char pad2070[4];
    V3 aim2074;
    V3 aim2080;
    void FUN_000359c0(int n);
    void FUN_000350c0(V3 *out);
    void FUN_00035550(V3 *out);
    float FUN_000354c0();
    bool FUN_0003a440(V3 *w, V3 *v, float a, int c2c, Target *t);
    Target *FUN_00039c60(V3 *w, V3 *v, int c28, int c2c, unsigned int flags, int z0, int z1);
    void FUN_0003ffa0(Target *t, int z);
};

struct Pool {
    Stats *FUN_00059a30();
};

struct Owner {
    Pool *FUN_000592a0();
};

struct Transform {
    void FUN_0022be40(V3 *p);
    void FUN_00221d20(float a);
};

struct Rig {
    char pad0[0x18];
    Transform transform;
};

struct Config {
    char pad0[0x14];
    float f14;
    V3 vec18;
    float f24;
    int i28;
    int i2c;
};

namespace hulkfight { namespace motion {

class FlyingAutoTargetAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int a0, float a1);
    char pad04[0x18];
    Config *cfg;     // 0x1c
    Owner *owner;    // 0x20
    Rig *rig;        // 0x24
    Target *tgt;     // 0x28
};

char FlyingAutoTargetAction::vfunc_5(int a0, float a1)
{
    if (a0 != 0)
        return 1;
    if (rig == 0)
        return 0;

    Pool *pool = owner->FUN_000592a0();
    Stats *stats = pool->FUN_00059a30();
    stats->FUN_000359c0(3);
    V3 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;
    stats->FUN_000350c0(&w);
    V3 t;
    stats->FUN_00035550(&t);
    V3 v = t;
    bool usedFallback = false;

    if (tgt == 0) {
        V3 z;
        v = stats->aim2080;
        z.x = 0.0f; z.y = 0.0f; z.z = 0.0f;
        if (v.FUN_0022d2b0(&z, 1e-5f)) {
            v = stats->aim2074;
            z.x = 0.0f; z.y = 0.0f; z.z = 0.0f;
            if (v.FUN_0022d2b0(&z, 1e-5f)) {
                v = stats->aim2064;
                z.x = 0.0f; z.y = 0.0f; z.z = 0.0f;
                if (v.FUN_0022d2b0(&z, 1e-5f)) {
                    v = t;
                    usedFallback = true;
                }
            }
        }

        Target *found = stats->target;
        bool direct = false;
        if (found) {
            if (stats->FUN_0003a440(&w, &v, 6.2831855f, cfg->i2c, found))
                direct = true;
        }
        if (!direct) {
            found = stats->FUN_00039c60(&w, &v, cfg->i28, cfg->i2c, 0x80000000u, 0, 0);
            if (!usedFallback && found == 0) {
                v = t;
                found = stats->FUN_00039c60(&w, &v, cfg->i28, cfg->i2c, 0x80000000u, 0, 0);
            }
        }
        if (found)
            found->v0();
        if (tgt)
            tgt->v1();
        tgt = found;
    }

    V3 dest = w;
    if (tgt) {
        if (stats->target == 0)
            stats->FUN_0003ffa0(tgt, 0);
        V3 p = tgt->pos;
        v.x = p.x - w.x;
        v.y = p.y - w.y;
        v.z = p.z - w.z;
        float h = FUN_00224f10(&v);
        V3 rv = cfg->vec18;
        FUN_00224d70(h + 3.14159274f, &rv);
        V3 q;
        q.x = rv.x + p.x;
        q.y = rv.y + p.y;
        q.z = rv.z + p.z;
        if (tgt->kind == 1) {
            Mesh *m = tgt->mesh;
            if (m) {
                Info *info = m->info;
                if (info) {
                    int type = m->type;
                    if (type != 3 && type != 4)
                        q.y = q.y + info->height;
                }
            }
        }
        V3 d;
        d.x = q.x - w.x;
        d.y = q.y - w.y;
        d.z = q.z - w.z;
        float len = d.FUN_0022d110();
        float c24 = cfg->f24;
        if (c24 < 0.0f) {
            dest = q;
        } else {
            double s = (double)c24 * (double)a1;
            if (s > (double)len)
                dest = q;
            else
                dest.FUN_00011160((float)s, &d);
        }
    }
    rig->transform.FUN_0022be40(&dest);

    float cur = stats->FUN_000354c0();
    float ang = FUN_00224ea0(v.x, v.z);
    float c14 = cfg->f14;
    float out = ang;
    if (!(c14 <= 0.0f)) {
        float r = FUN_00224fc0(cur, ang);
        float step = c14 * a1;
        if (!(AbsF(r) <= step)) {
            if (r < 0.0f)
                out = cur - step;
            else
                out = step + cur;
        }
    }
    rig->transform.FUN_00221d20(out);
    return 1;
}

}}
