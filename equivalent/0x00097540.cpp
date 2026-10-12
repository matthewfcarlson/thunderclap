// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 30/30)
// FUN_00097540 @ 0x00097540
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    void FUN_00095e80(float s, const V3 *v);
};

struct Stats {
    char pad0[0x148];
    Stats *f148;
    char FUN_00035660(V3 *out);
};

struct Ent {
    char pad0[8];
    Stats *f8;
    int kind;
    char pad10[0x50 - 0x10];
    V3 pos;
};


class Level {
public:
    char FUN_00039440(Ent *e, V3 *h, float *o, int z);
};

double __cdecl FUN_00097290(V3 a, V3 b);

union PtrOrFloat3 {
    V3 *p;
    float f;
};

union EntOrFloat {
    Ent *e;
    float f;
};

char FUN_00097540(Level *a1, V3 *a2, V3 *a3, float a4, float a5, Ent *a6, V3 *a7, V3 *a8, char a9)
{
    struct Frame {
        float s0;
        V3 w;
        V3 d;
        V3 hpos;
        V3 q3;
        V3 c34;
        V3 c40;
        V3 c4c;
        V3 u;
    } f;

    V3 *dir = a3;
    float hd;
    float hdist;
    a7->x = a4 * dir->x;
    a7->y = a4 * dir->y;
    a7->z = a4 * dir->z;
    Ent *ent = a6;
    if (ent == 0)
        return 0;
    if (!a1->FUN_00039440(ent, &f.hpos, &f.s0, 0))
        return 0;
    if (a8 != 0) {
        a8->x = f.hpos.x;
        a8->y = f.hpos.y;
        a8->z = f.hpos.z;
    }
    V3 *org = a2;
    f.d.x = f.hpos.x - org->x;
    f.c40.x = f.d.x;
    f.d.y = f.hpos.y - org->y;
    f.c40.y = f.d.y;
    f.d.z = f.hpos.z - org->z;
    f.c40.z = f.d.z;
    hdist = (float)sqrt(f.c40.z * f.c40.z + f.c40.x * f.c40.x);
    f.d.FUN_0022d110();
    a7->x = (float)(f.d.x * a4);
    f.c40.x = a7->x;
    a7->y = f.d.y * a4;
    double zp = (double)f.d.z * a4;
    a7->z = (float)zp;
    hd = (float)sqrt(zp * zp + (double)f.c40.x * f.c40.x);
    if (!(hdist > 3.0f))
        return 1;
    if (!(hd > 1.0f))
        return 1;

    f.w = ent->pos;
    if (ent->kind == 1) {
        ent->f8->FUN_00035660(&f.w);
    } else if (ent->kind == 5) {
        Stats *s = ent->f8->f148;
        if (s != 0)
            s->FUN_00035660(&f.w);
    }
    double lsq = f.w.z * f.w.z + f.w.y * f.w.y + f.w.x * f.w.x;
    if (lsq > 225.0f) {
        f.w.FUN_0022d110();
        f.w.x = f.w.x * 15.0f;
        f.w.y = f.w.y * 15.0f;
        f.w.z = f.w.z * 15.0f;
    }
    f.c4c = f.w;
    f.c34.x = org->x;
    f.c34.x = f.c34.x - f.hpos.x;
    f.c34.y = org->y;
    f.c34.z = org->z;
    f.c34.y = f.c34.y - f.hpos.y;
    f.c34.z = f.c34.z - f.hpos.z;
    f.u.x = f.c34.x;
    f.u.y = 0.0f;
    f.u.z = f.c34.z;
    f.u.FUN_0022d110();
    double v = f.c4c.z * f.u.z + f.c4c.x * f.u.x + f.u.y * 0.0f + hd;
    if (v < 1.0)
        v = 1.0;
    double ratio = hdist / v;
    float t;
    if (ratio < 30.0)
        t = (float)ratio;
    else
        t = 30.0f;

    f.c34.x = f.hpos.x;
    f.c34.z = f.hpos.z;
    f.c34.y = f.hpos.y;
    f.c34.y = 0.0f;
    f.w.x = f.w.x * t;
    f.w.y = f.w.y * t;
    f.w.z = f.w.z * t;
    f.c4c.x = f.w.x + f.hpos.x;
    f.c4c.y = f.w.y + f.hpos.y;
    f.c4c.z = f.w.z + f.hpos.z;
    f.c40.x = f.c4c.x;
    f.c40.y = 0.0f;
    f.c40.z = f.c4c.z;
    f.c40.x = f.c40.x - org->x;
    f.c40.z = f.c40.z - org->z;
    f.c34.x = f.c34.x - org->x;
    f.c34.z = f.c34.z - org->z;
    double ret = FUN_00097290(f.c40, f.c34);
    if (ret > 45.0f)
        return 1;

    if (a8 != 0) {
        a8->x = f.c4c.x;
        a8->y = f.c4c.y;
        a8->z = f.c4c.z;
    }
    f.q3.x = f.c4c.x - org->x;
    f.q3.y = f.c4c.y - org->y;
    f.q3.z = f.c4c.z - org->z;
    f.c40.x = f.q3.x;
    f.c4c.x = f.q3.x;
    f.c40.y = f.q3.y;
    f.c4c.y = 0.0f;
    f.c4c.z = f.q3.z;
    f.c4c.y = 0.0f;
    if (f.c4c.FUN_00018990() < 2.0f)
        return 1;
    f.q3.FUN_0022d110();
    a7->FUN_00095e80(a4, &f.q3);
    if (a9) {
        a7->y = (float)(((double)t * t * a5 * 0.5f + f.c40.y) / t);
    }
    return 1;
}
