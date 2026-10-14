// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 83/84, incomplete)
// CAvoidBehaviour::vfunc_3 @ 0x0010a040
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    float FUN_000111f0();
    char FUN_0022d2b0(const V3 *other, float eps);
    void FUN_000344b0(float s);
};

struct Rng {
    float FUN_00078780();
};
Rng *__cdecl FUN_000964d0();

struct Pos {
    void FUN_00059a50(V3 *out);
};

struct Ent1fc {
    V3 *FUN_001fc150(V3 *a, V3 *b, V3 *c);
};
struct Sub58 {
    Ent1fc *FUN_000fde20(V3 *out);
};
struct Sub1ca0 {
    char pad00[0x58];
    Sub58 f58;
};

struct Node1 {
    char pad00[0x10];
    Pos *f10;
    void FUN_000368d0(int a);
};

struct Ent74 {
    char pad00[0x72];
    char b72;
};
struct Ent128 {
    char pad00[0x74];
    Ent74 *f74;
};
struct Fighter128 {
    Ent128 *FUN_001d72e0();
};

struct Stats {
    char pad00[0x10];
    Pos *f10;
    char pad14[0x128 - 0x14];
    Fighter128 *f128;
    char pad12c[0x328 - 0x12c];
    int f328;
    char pad32c[0x1ca0 - 0x32c];
    char *f1ca0;
    char pad1ca4[0x1cf8 - 0x1ca4];
    float f1cf8;
    float f1cfc;
    float f1d00;
    void FUN_00035550(V3 *out);
    void FUN_000368d0(int a);
    void FUN_00035fa0(int a);
};


struct Owner20 {
    char pad00[0x124];
    Node1 *f124;
    void FUN_00025260(int a, int b, int c);
    void FUN_000253c0(int a);
};
struct Owner {
    char pad00[0x20];
    Owner20 *f20;
};

struct WorldC {
    void FUN_001dcf60(int a);
};
struct World {
    char pad00[0xc];
    WorldC *fc;
};
extern World *DAT_004dd700;
extern float DAT_004a1eac[4];

V3 *__cdecl FUN_00083e00(V3 *out, V3 *dir, float t);
float __cdecl FUN_00018710(float *a, float *b);
void __cdecl FUN_00224d70(float angle, V3 *axis);

struct Frame {
    char pad0[3];
    char flagA;             // 3
    float f4;
    float f8;
    char pad12[3];
    char flag2;             // 15
    V3 v16;
    V3 P;                   // 28
    V3 v40;
    V3 v52;
    V3 v64;
    float A;                // 76
    float M;                // 80
    float f84;
    V3 v88;
    V3 v100;
    float f112;
    char pad116[3];
    char b119;
    V3 v120;
    V3 v132;
    V3 v144;
    V3 v156;
    V3 v168;
    V3 v180;
    V3 v192;
    V3 v204;
    V3 v216;
    V3 v228;
};

class CAvoidBehaviour {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(Owner *owner, Stats *st, V3 *out, float dt, char flag);
    virtual void vfunc_4();
    char pad04[0x10 - 4];
    V3 v10;
    V3 v1c;
    char pad28[4];
    float f2c;
    float f30;
    char b34;
    char pad35[3];
    char FUN_00109df0(Owner *o, V3 *p, V3 *q, float a, V3 *r, V3 *s, V3 *t, int u);
};


char CAvoidBehaviour::vfunc_3(Owner *owner, Stats *st, V3 *out, float dt, char flag)
{
    Frame f;
    out->x = 0;
    out->y = 0;
    out->z = 0;
    if (st == 0)
        return false;
    f.A = st->f1cf8;
    float B = st->f1cfc;
    float C = st->f1d00;
    f.f8 = f.A * 4.0f;
    f.f84 = f.f8;
    if (!(B > f2c))
        B = f2c;
    float R = B * C;
    if (R < f.f8)
        f.M = f.f8;
    else
        f.M = R;
    if (f.A <= 0.0f)
        return false;
    if (f.M <= 0.0f)
        return false;
    f.f8 = v10.FUN_0022d110();
    if (f.f8 == 0.0f)
        return false;
    f.flagA = 0;
    if (f2c > 0.1f) {
        st->FUN_00035550(&f.v40);
        if (f.v40.z * v10.z + f.v40.y * v10.y + f.v40.x * v10.x < 0.99f)
            f.flagA = 1;
        else
            f.flagA = 0;
    } else {
        f.v40.x = v10.x;
        f.v40.z = v10.z;
    }
    f.v40.y = 0;
    if (f.v40.FUN_0022d110() == 0.0f)
        return false;
    f30 = f30 - dt;
    if (f30 > 0.0f && !flag && (!f.flagA || b34)) {
        *out = v1c;
        return b34;
    }
    st->f10->FUN_00059a50(&f.P);
    Owner *ow = owner;
    Node1 *nd = ow->f20->f124;
    if (nd) {
        nd->f10->FUN_00059a50(&f.v192);
        f.f4 = f.v192.y - f.P.y;
        unsigned int bits = *(unsigned int *)&f.f4 & 0x7fffffff;
        *(unsigned int *)&f.f4 = bits;
        if (f.f4 >= 1.0f)
            ow->f20->f124->FUN_000368d0(0);
    }
    f.P.y = f.P.y + 0.5f;
    f.flag2 = 0;
    if (st->f1ca0) {
        Sub58 *s58 = (Sub58 *)(st->f1ca0 + 0x58);
        if (s58) {
            Ent1fc *e = s58->FUN_000fde20(&f.v16);
            if (e) {
                V3 *r = e->FUN_001fc150(&f.v204, &f.v16, &f.P);
                f.v40.x = r->x;
                f.v40.y = r->y;
                f.v40.z = r->z;
                f.v40.y = 0;
                f.v40.FUN_0022d110();
                out->x = f.v40.x;
                out->y = f.v40.y;
                out->z = f.v40.z;
                f.flag2 = 1;
            }
        }
    }
    ow->f20->FUN_00025260(1, 0, 0);
    ow->f20->FUN_000253c0(1);
    DAT_004dd700->fc->FUN_001dcf60(1);
    st->FUN_00035fa0(0);
    Fighter128 *f128 = st->f128;
    if (f128) {
        if (f128->FUN_001d72e0()) {
            Ent128 *e128 = f128->FUN_001d72e0();
            if (e128->f74)
                e128->f74->b72 = 0;
        }
    }
    st->FUN_000368d0(0);

    FUN_00083e00(&f.v88, &f.v40, f.M);
    f.v16.x = f.v88.x + f.P.x;
    f.v100.x = f.v88.x;
    f.v100.y = f.v88.y;
    f.v100.z = f.v88.z;
    f.v16.y = f.v88.y + f.P.y;
    f.v16.z = f.v88.z + f.P.z;
    char r1 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v120, &f.v168, &f.v100, st->f328);
    f.b119 = !r1;
    char bl = 0;
    bool success = false;
    if (!r1) {
        success = true;
    } else if (f.flagA) {
        V3 *r = FUN_00083e00(&f.v204, &v10, st->f1d00);
        f.v88.x = r->x;
        f.v88.y = r->y;
        f.v88.z = r->z;
        f.v16.x = f.v88.x + f.P.x;
        f.v100.z = r->z;
        f.v16.y = f.v88.y + f.P.y;
        f.v100.x = r->x;
        f.v100.y = r->y;
        f.v16.z = f.v88.z + f.P.z;
        char r2 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v120, &f.v168, &f.v100, st->f328);
        bl = !r2;
        success = (bl != 0);
    }
    if (!success) {
        st->FUN_000368d0(1);
        st->FUN_00035fa0(1);
        Rng *rng = FUN_000964d0();
        f30 = (rng->FUN_00078780() * 0.5f + 1.0f) * DAT_004a1eac[0];
        b34 = f.flag2;
        v1c = *out;
        return f.flag2;
    }

    f.v16.x = f.v120.x - f.P.x;
    f.v16.y = f.v120.y - f.P.y;
    f.v16.z = f.v120.z - f.P.z;
    f.f4 = f.v16.FUN_00018990();
    if (bl || f.f4 > f.f8) {
        *out = f.v40;
        v1c = *out;
        if (!bl)
            f2c = f.f8 / f.f4;
        st->FUN_000368d0(1);
        st->FUN_00035fa0(1);
        Rng *rng = FUN_000964d0();
        f30 = (rng->FUN_00078780() * 0.5f + 1.0f) * DAT_004a1eac[1];
        b34 = 1;
        return true;
    }

    f.f112 = f.f4 / f.M;
    f.f8 = 0.1f;
    f2c = FUN_00018710(&f.f112, &f.f8);
    f.v52 = f.v40;
    f.v64 = f.v40;
    f.f8 = (1.0f - f2c) * 0.785398185f + 0.261799395f;
    FUN_00224d70(-f.f8, &f.v64);
    FUN_00224d70(f.f8, &f.v52);
    f.f112 = f.M * 0.5f;
    f.f84 = FUN_00018710(&f.f112, &f.f84);
    f.v64.FUN_000344b0(f.f84);
    f.v52.FUN_000344b0(f.f84);
    f.v16.x = f.v64.x + f.P.x;
    f.v180 = f.v52;
    f.v16.y = f.v64.y + f.P.y;
    f.v156 = f.v64;
    f.v16.z = f.v64.z + f.P.z;
    char p1 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v132, &f.v216, &f.v156, st->f328);
    f.v16.x = f.v52.x + f.P.x;
    f.v16.y = f.v52.y + f.P.y;
    f.v16.z = f.v52.z + f.P.z;
    char p2 = FUN_00109df0(ow, &f.P, &f.v16, f.A, &f.v144, &f.v228, &f.v180, st->f328);
    bl = !p1;
    f.flagA = !p2;
    st->FUN_000368d0(1);
    st->FUN_00035fa0(1);
    if (ow->f20->f124)
        ow->f20->f124->FUN_000368d0(1);
    int idx = 1;
    if (bl)
        idx = 2;
    if (f.flagA)
        idx++;
    Rng *rng2 = FUN_000964d0();
    f30 = (rng2->FUN_00078780() * 0.5f + 1.0f) * DAT_004a1eac[idx];
    if (bl) {
        if (!f.flagA) {
            *out = f.v52;
        } else {
            f.v16.x = f.v120.x - f.P.x;
            f.v16.y = f.v120.y - f.P.y;
            f.v16.z = f.v120.z - f.P.z;
            f.f8 = f.v16.FUN_000111f0();
            f.v16.x = f.v132.x - f.P.x;
            f.v16.y = f.v132.y - f.P.y;
            f.v16.z = f.v132.z - f.P.z;
            f.f4 = f.v16.FUN_000111f0();
            f.v16.x = f.v144.x - f.P.x;
            f.v16.y = f.v144.y - f.P.y;
            f.v16.z = f.v144.z - f.P.z;
            float d3 = f.v16.FUN_000111f0();
            if (f.f8 > f.f4 && f.f8 > d3 && b34)
                *out = v1c;
            else if (f.f4 > d3)
                *out = f.v64;
            else
                *out = f.v52;
        }
    } else if (f.flagA) {
        *out = f.v64;
    } else {
        if (st->f1d00 * 0.5f > f.f4)
            f.f4 = f.v100.z * f.v40.x - f.v100.x * f.v40.z;
        else
            f.f4 = f.v100.z * v10.x - f.v100.x * v10.z;
        if (f.f4 != 0.0f && !f.v100.FUN_0022d2b0(&f.v88, 1e-05f)) {
            if (f.f4 > 0.0f)
                *out = f.v52;
            else
                *out = f.v64;
        } else {
            if (f.v168.z * f.v40.x - f.v168.x * f.v40.z > 0.0f)
                *out = f.v64;
            else
                *out = f.v52;
        }
    }
    out->FUN_0022d110();
    v1c = *out;
    b34 = 1;
    return true;
}
