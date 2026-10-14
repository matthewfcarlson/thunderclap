// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 26/26)
// hulkfight::motion::ClimbLocomotionAction::vfunc_5 @ 0x0015f070
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3 *a, const V3 *b);
    float FUN_00018990();
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

extern "C" float __cdecl FUN_00018a20(float v);
extern "C" bool __cdecl FUN_00018960(float a, float b, float eps);
extern "C" void __cdecl FUN_00224d70(float angle, V3 *v);
extern "C" float __cdecl FUN_00224f10(V3 *v);
extern V3 DAT_004b4d60;

struct Mat {
    char data[0x30];
    void FUN_0022baf0(V3 *axis, float ang);
    void FUN_0022c3b0(V3 *in, V3 *out);
};

struct Stats {
    char pad0[0x2064];
    V3 vec2064;
    float f2070;
    char pad2074[0x20a8 - 0x2074];
    int i20a8;
    void FUN_000359c0(int n);
    char FUN_00035550(V3 *out);
};

struct Pool {
    Stats *FUN_00059a30();
    void FUN_00059a50(V3 *out);
};

struct Owner {
    Pool *FUN_000592a0();
};

struct Transform {
    void FUN_0022be40(V3 *p);
};

struct Rig {
    char pad0[0x18];
    Transform transform;
};

struct Obj {
    char pad0[0x12e0];
    float f12e0;
    float f12e4;
    float f12e8;
};

struct Pair {
    V3 u;
    V3 t;
    float o0c;
};

struct Loc {
    V3 dir;
    float x;
    V3 r;
};

namespace hulkfight { namespace motion {

class ClimbLocomotionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int a0, float a1);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(float *out);
    char pad04[0x18];
    Owner *owner;   // 0x1c
    Obj *obj;       // 0x20
    Rig *rig;       // 0x24
    float FUN_0015ebc0(float k, float a, float b);
};

char ClimbLocomotionAction::vfunc_5(int a0, float a1)
{
    if (a0 != 0)
        return 1;
    if (obj == 0)
        return 0;

    Pool *pool = owner->FUN_000592a0();
    Stats *stats = pool->FUN_00059a30();
    Loc loc;
    loc.x = -1.0f;
    vfunc_8(&loc.x);
    stats->FUN_000359c0(4);
    V3 q;
    pool->FUN_00059a50(&q);
    obj->f12e0 = 0.0f;
    V3 &dir = loc.dir;
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 0.0f;
    if (!stats->FUN_00035550(&dir))
        return 0;
    dir.y = 0.0f;
    dir.FUN_0022d110();

    float k = stats->f2070;
    if (stats->i20a8 >= 0) {
        if (!(k <= 0.0f)) {
            if (!(k <= 0.5f))
                k = 1.0f;
            else
                k = 0.5f;
        } else {
            k = 0.0f;
        }
    }

    float nm;
    if (!(AbsF(k) <= 1e-5f)) {
        V3 a = stats->vec2064;
        V3 b = stats->vec2064;
        double dot = ((double)a.z * dir.z + (double)a.x * dir.x) + (double)a.y * dir.y;
        b.y = (float)(b.y * dot);
        b.z = (float)(b.z * dot);
        a.x = (float)((double)a.x - (double)a.x * dot);
        a.y = a.y - b.y;
        a.z = a.z - b.z;
        a.FUN_0022d110();
        float m = FUN_00018a20(a.y);
        if (FUN_00018960(AbsF(a.y), 1.0f, 1e-5f)) {
            nm = -m;
        } else {
            V3 up;
            up.x = 0.0f;
            up.y = 1.0f;
            up.z = 0.0f;
            V3 &r = loc.r;
            r.FUN_000111b0(&a, &up);
            double d2 = ((double)r.z * dir.z + (double)r.x * dir.x) + (double)r.y * dir.y;
            if (d2 > 0.0)
                nm = m;
            else
                nm = -m;
        }
    } else {
        nm = 0.0f;
    }

    float o0 = obj->f12e0;
    float o1 = obj->f12e4;
    float nk = FUN_0015ebc0(k, o1, o0);
    float p1 = obj->f12e4;
    float p2 = obj->f12e8;

    bool direct = false;
    float ang = 0.0f;
    float val = 0.0f;
    float diff = AbsF(p1 - nm);
    if (!(diff <= 1e-5f)) {
        direct = false;
    } else {
        direct = FUN_00018960(p2, nk, 1e-5f);
    }
    if (!direct) {
        Pair L;
        L.o0c = diff;
        V3 &t = L.t;
        V3 &u = L.u;
        t.x = DAT_004b4d60.x * p2;
        t.y = DAT_004b4d60.y * p2;
        t.z = DAT_004b4d60.z * p2;
        FUN_00224d70(p1, &t);
        u.x = DAT_004b4d60.x * nk;
        u.y = DAT_004b4d60.y * nk;
        u.z = DAT_004b4d60.z * nk;
        FUN_00224d70(nm, &u);
        V3 w;
        w.x = u.x - t.x;
        w.y = u.y - t.y;
        w.z = u.z - t.z;
        float len = w.FUN_0022d110();
        if (loc.x <= 0.0f) {
            direct = true;
        } else {
            float s = loc.x * a1;
            if (len <= s) {
                direct = true;
            } else {
                w.x = w.x * s + t.x;
                w.y = w.y * s + t.y;
                w.z = w.z * s;
                w.z = w.z + t.z;
                ang = FUN_00224f10(&w);
                val = w.FUN_00018990();
            }
        }
    }
    if (direct) {
        ang = nm;
        val = nk;
    }
    obj->f12e4 = ang;
    obj->f12e8 = val;

    Mat M;
    M.FUN_0022baf0(&dir, obj->f12e4);
    V3 r2;
    r2.x = 0.0f;
    r2.y = a1 * obj->f12e8;
    r2.z = 0.0f;
    V3 out;
    M.FUN_0022c3b0(&r2, &out);
    out.x = out.x + q.x;
    out.y = q.y + out.y;
    out.z = q.z + out.z;
    rig->transform.FUN_0022be40(&out);
    return 1;
}

}}
