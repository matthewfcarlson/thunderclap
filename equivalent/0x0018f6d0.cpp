// STATUS: equivalent (tools/equiv.py level 3: 3050 inputs, branch coverage 98/98)
// hulkfight::motion::TankLocomotionAction::vfunc_5 @ 0x0018f6d0
#include "decls/address.h"
#include "decls/data/game/hulkfight/motion.h"
extern "C" double sqrt(double);
extern "C" double atan(double);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct Vec3_18f6d0 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const Vec3_18f6d0 *other, float eps);
};

struct Pt_18f6d0 {
    float x, y, z;
};
extern char FUN_00011090;
void __stdcall FUN_00011520(void *p, unsigned int size, int count, void *ctor);

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float a);
    void FUN_0022ba30(float a);
    void FUN_0022ba70(float a);
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
    void FUN_0022c2b0(const Vec3_18f6d0 *in, Vec3_18f6d0 *out);
};

struct Xform_18f6d0 {
    Matrix *FUN_00221c40();
    void FUN_00221c60(Matrix *m);
};

struct Skel_18f6d0 {
    char pad00[0x10];
    Xform_18f6d0 xf;
};

struct Driver {
    char pad00[0x18];
    Xform_18f6d0 xf;
};

struct Part_18f6d0 {
    char pad00[0xe8];
    char disabled;
};

struct Entity {
    char pad000[0x140];
    int f140;
    char pad144[0x1d8 - 0x144];
    Vec3_18f6d0 v1d8;
    char pad1e4[0x1ac4 - 0x1e4];
    Vec3_18f6d0 v1ac4;
    char pad1ad0[0x1ca0 - 0x1ad0];
    Part_18f6d0 *part;
    char pad1ca4[0x2064 - 0x1ca4];
    Vec3_18f6d0 v2064;
    float f2070;
    Vec3_18f6d0 v2074;
    Vec3_18f6d0 v2080;
    void FUN_000356c0(Vec3_18f6d0 *out);
    void FUN_00035550(Vec3_18f6d0 *out);
    void FUN_00035230(Vec3_18f6d0 *out);
    void FUN_000357e0();
    void FUN_000359c0(int a);
    void FUN_000368d0(int a);
    void FUN_00035fa0(int a);
};

struct Holder_18f6d0 {
    Entity *FUN_00059a30();
    Skel_18f6d0 *FUN_00059a40();
    void FUN_00059a50(Vec3_18f6d0 *out);
};

struct HolderSource_18f6d0 {
    Holder_18f6d0 *FUN_000592a0();
};

struct Zone;
struct Mid_18f6d0 {
    Zone *FUN_00204200(float x, float y, float z);
    bool FUN_00204440(Zone *z);
};

struct Holder54_18f6d0 {
    Mid_18f6d0 *FUN_000862a0();
};

struct Player_18f6d0 {
    void FUN_00025260(int a, int b, int c);
};

struct World {
    char pad00[0x20];
    Player_18f6d0 *player;
    char pad24[0x54 - 0x24];
    Holder54_18f6d0 *holder;
};

struct Settings_18f6d0 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    Vec3_18f6d0 v34;
    float f40;
    float f44;
    float f48;
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    float f64;
};


float __cdecl FUN_00224f10(Vec3_18f6d0 *v);
float __cdecl FUN_00224fc0(float a, float b);
float __cdecl FUN_00083d90(float *v);
void __cdecl FUN_00224d70(float angle, Vec3_18f6d0 *v);
char __cdecl FUN_00202560(Vec3_18f6d0 *origin, float dist, int a, Vec3_18f6d0 *outB, Vec3_18f6d0 *outA, int b, int c, int d);

static __forceinline float FAbs(float v)
{
    union {
        float f;
        unsigned u;
    } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

static __forceinline bool NearZero(Vec3_18f6d0 *v)
{
    Vec3_18f6d0 z;
    z.x = 0.0f;
    z.y = 0.0f;
    z.z = 0.0f;
    return v->FUN_0022d2b0(&z, 1e-5f);
}

namespace hulkfight {
namespace motion {

class TankLocomotionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x18];
    Settings_18f6d0 *volatile settings;
    HolderSource_18f6d0 *owner;
    Driver *volatile driver;
    int cursor;
    char hit[4];
    Vec3_18f6d0 cacheHit[4];
    Vec3_18f6d0 cacheNrm[4];
    float a90;
    float vel[4];
};

bool TankLocomotionAction::vfunc_5(int a, float dt)
{
    if (a != 0)
        return true;
    if (driver == 0)
        return false;
    Holder_18f6d0 *h = owner->FUN_000592a0();
    Entity *ent = h->FUN_00059a30();
    Skel_18f6d0 *sk = h->FUN_00059a40();
    if (FAbs(dt) <= 1e-5f) {
        driver->xf.FUN_00221c60(sk->xf.FUN_00221c40());
        return true;
    }

    Vec3_18f6d0 pos;
    h->FUN_00059a50(&pos);
    Vec3_18f6d0 vA;
    vA.x = 0.0f;
    vA.y = 0.0f;
    vA.z = 0.0f;
    ent->FUN_000356c0(&vA);
    vA.y = 0.0f;
    Vec3_18f6d0 vB = vA;
    float lenB = vB.FUN_0022d110();
    Vec3_18f6d0 vC;
    vC.x = 0.0f;
    vC.y = 0.0f;
    vC.z = 0.0f;
    ent->FUN_00035550(&vC);
    float hC = FUN_00224f10(&vC);
    Vec3_18f6d0 W = ent->v2064;
    if (NearZero(&W))
        W = vC;
    Vec3_18f6d0 U = ent->v2074;
    if (NearZero(&U)) {
        U = ent->v2080;
        U.FUN_0022d110();
        if (NearZero(&U))
            U = W;
    }
    float hU = FUN_00224f10(&U);
    double dot1 = (U.z * W.z + U.y * W.y) + U.x * W.x;
    float s98 = dot1 * ent->f2070;
    volatile float kb4;
    if (dot1 > 0.0f)
        kb4 = settings->f14;
    else
        kb4 = settings->f18;

    Vec3_18f6d0 X = ent->v1ac4;
    if (!NearZero(&X)) {
        float hX = FUN_00224f10(&X);
        float d = FUN_00224fc0(hU, hX);
        float ad = FAbs(d);
        if (ad > 1.5707963705062866f) {
            if (d < 0.0f)
                hU = hX + 1.5707963705062866f;
            else
                hU = hX - 1.5707963705062866f;
        }
    }

    float r = (FUN_00224fc0(hC, hU) * 0.31830987334251404f) * settings->f28;
    float k28 = settings->f28;
    float k24 = settings->f24;
    if (k24 > 0.0f) {
        float am = FAbs(a90);
        float mn = am < k24 ? am : k24;
        r = r - (((FUN_00083d90(&a90) * mn) / k24) * k28);
    }
    a90 = r * dt + a90;
    Vec3_18f6d0 vF8 = (*(Vec3_18f6d0*)&DAT_004bfc24);
    float ang = (a90 * dt) + hC;
    FUN_00224d70(ang, &vF8);
    float spd = ((vB.z * vF8.z + vB.y * vF8.y) + vB.x * vF8.x) * lenB;
    double P = (double)kb4 * s98;
    double D = P - spd;
    double V;
    if (D > 0.0f) {
        volatile float lim = dt * settings->f1c;
        if (D < lim)
            V = P;
        else
            V = lim + spd;
    } else {
        volatile float lim2 = dt * settings->f20;
        if (D > -((double)dt * settings->f20))
            V = P;
        else
            V = spd - lim2;
    }
    Vec3_18f6d0 vG;
    vG.x = vF8.x * V;
    vG.y = vF8.y * V;
    vG.z = vF8.z * V;
    Vec3_18f6d0 v48;
    v48.x = vG.x - vA.x;
    v48.y = vG.y - vA.y;
    v48.z = vG.z - vA.z;
    Vec3_18f6d0 vE = v48;
    float lenE = vE.FUN_0022d110();
    Matrix *M = sk->xf.FUN_00221c40();
    Matrix m2e0;
    memcpy(&m2e0, M, 0x40);
    float hz = settings->f2c * 0.5f;
    float hx = settings->f30 * 0.5f;
    Vec3_18f6d0 c3 = settings->v34;
    volatile float k16c = settings->f44;
    volatile float k168 = settings->f4c;
    volatile float s98b = settings->f40;
    volatile float k154 = settings->f48;
    volatile float s34 = settings->f54;
    volatile float L14 = settings->f64;
    volatile float s44 = settings->f50;
    volatile float s1c = settings->f58;
    if (ent->f140 == 3) {
        s1c = settings->f5c;
        L14 = settings->f60;
    }
    Vec3_18f6d0 vN = ent->v1d8;
    float lenN = vN.FUN_0022d110();

    float inp[12];
    inp[0] = c3.x + hx;
    inp[1] = c3.y;
    inp[2] = c3.z - hz;
    inp[3] = c3.x - hx;
    inp[4] = c3.y;
    inp[5] = c3.z - hz;
    inp[6] = c3.x + hx;
    inp[7] = c3.y;
    inp[8] = c3.z + hz;
    inp[9] = c3.x - hx;
    inp[10] = c3.y;
    inp[11] = c3.z + hz;
    Pt_18f6d0 pts[4];
    FUN_00011520(pts, 12, 4, &FUN_00011090);
    for (int j = 0; j < 4; j++)
        m2e0.FUN_0022c2b0((Vec3_18f6d0 *)(inp + j * 3), (Vec3_18f6d0 *)&pts[j]);

    float y0 = pos.y;
    Vec3_18f6d0 v15c;
    v15c.x = 0.0f;
    v15c.y = 0.0f;
    v15c.z = 0.0f;
    ent->FUN_00035230(&v15c);
    if (v15c.y > y0)
        y0 = v15c.y;
    volatile float s78 = -s1c;
    pos.y = 0.0f;

    int contacts = 0;
    Vec3_18f6d0 hitp;
    Vec3_18f6d0 vH;
    Vec3_18f6d0 Q;
    for (int i = 0; i < 4; i++) {
        vH.x = 0.0f;
        vH.y = 1.0f;
        vH.z = 0.0f;
        if (i != cursor && (ent->part == 0 || ent->part->disabled == 0)) {
            hitp = cacheHit[i];
            vH = cacheNrm[i];
        } else {
            Q.x = pts[i].x;
            Q.y = pts[i].y + 2.0f;
            Q.z = pts[i].z;
            if (Q.y < y0)
                Q.y = y0;
            ent->FUN_000368d0(0);
            ent->FUN_00035fa0(0);
            DAT_004dd700->player->FUN_00025260(0, 0, 0);
            char hq = FUN_00202560(&Q, 100.0f, 0, &hitp, &vH, 0, 0, 0);
            hit[i] = hq;
            if (vH.y < 0.05f)
                hit[i] = 0;
            DAT_004dd700->player->FUN_00025260(1, 0, 0);
            ent->FUN_000368d0(1);
            ent->FUN_00035fa0(1);
            if (!hq) {
                hitp.x = pos.x;
                hitp.y = y0;
                hitp.z = pos.z;
                if (DAT_004dd700->holder->FUN_000862a0()->FUN_00204440(DAT_004dd700->holder->FUN_000862a0()->FUN_00204200(Q.x, Q.y, Q.z))) {
                    Vec3_18f6d0 dd;
                    dd.x = pos.x - pts[i].x;
                    dd.y = 0.0f;
                    dd.z = pos.z - pts[i].z;
                    dd.FUN_0022d110();
                    double dot3 = (dd.z * vG.z + dd.x * vG.x) + vG.y * dd.y;
                    if (dot3 < 0.0f) {
                        double nn = -dot3;
                        vG.x = dd.x * nn + vG.x;
                        vG.y = dd.y * nn + vG.y;
                        vG.z = dd.z * nn + vG.z;
                    }
                }
            }
            cacheHit[i] = hitp;
            cacheNrm[i] = vH;
        }

        float dy = pts[i].y - hitp.y;
        double Y;
        if (dy < s98b) {
            v48.x = pts[i].x - pos.x;
            v48.y = 0.0f;
            v48.z = pts[i].z - pos.z;
            v48.FUN_0022d110();
            char hf = hit[i];
            float force = (((s98b - dy) * k16c) + s78) - (k154 * vel[i]);
            if (hf) {
                float ay = FAbs(vH.y);
                double slope;
                if (ay <= 1e-5f)
                    slope = 1.5707963705062866f;
                else
                    slope = atan(sqrt(vH.z * vH.z + vH.x * vH.x) / vH.y);
                if (slope > s44) {
                    float fct = 1.0f - vH.y;
                    if (s44 < s34 && slope < s34)
                        fct = ((slope - s44) / (s34 - s44)) * fct;
                    Vec3_18f6d0 vS;
                    vS.x = vH.x;
                    vS.y = vH.y;
                    vS.z = vH.z;
                    vS.y = 0.0f;
                    vS.FUN_0022d110();
                    double t = ((fct * kb4) * dt) * 0.25f;
                    vS.y = vS.y * t;
                    vS.z = vS.z * t;
                    pos.x = vS.x * t + pos.x;
                    pos.y = vS.y + pos.y;
                    pos.z = vS.z + pos.z;
                }
            }
            contacts++;
            Y = ((force - ((((vE.z * v48.z + vE.x * v48.x) + vE.y * v48.y) * k168) * lenE)) - (((vN.z * v48.z + vN.x * v48.x) + vN.y * v48.y) * lenN));
        } else {
            Y = s78;
        }
        if (dy < 0.0f)
            pts[i].y = hitp.y;
        float nv = Y * dt + vel[i];
        vel[i] = nv;
        if (L14 > 0.0f) {
            if (nv < -L14)
                vel[i] = -L14;
            else if (nv > L14)
                vel[i] = L14;
        }
        float ny = dt * vel[i] + pts[i].y;
        pts[i].y = ny;
        pos.y = ny + pos.y;
    }

    pos.y = (pos.y * 0.25f) - c3.y;
    ent->FUN_000357e0();
    int mode = 1;
    if (contacts <= 2) {
        int k = 0;
        while (hit[k]) {
            k++;
            if (k >= 4) {
                mode = 3;
                break;
            }
        }
    }
    ent->FUN_000359c0(mode);

    Vec3_18f6d0 D1;
    D1.x = pts[1].x + pts[0].x;
    D1.y = pts[1].y + pts[0].y;
    D1.z = pts[0].z + pts[1].z;
    D1.x = D1.x - pts[2].x;
    D1.y = D1.y - pts[2].y;
    D1.z = D1.z - pts[2].z;
    D1.x = D1.x - pts[3].x;
    D1.y = D1.y - pts[3].y;
    D1.z = D1.z - pts[3].z;
    volatile float hy1 = D1.y * 0.5f;
    double L1 = sqrt((D1.z * 0.5f) * (D1.z * 0.5f) + (D1.x * 0.5f) * (D1.x * 0.5f));
    float pitch;
    if (FAbs((float)L1) <= 1e-5f)
        pitch = 0.0f;
    else
        pitch = (float)atan(hy1 / L1);
    if (!(pitch >= -s34)) {
        if (pitch > s34)
            pitch = s34;
        else
            pitch = -s34;
    } else if (pitch > s34) {
        pitch = s34;
    }

    Vec3_18f6d0 D2;
    D2.x = pts[0].x + pts[2].x;
    D2.y = pts[0].y + pts[2].y;
    D2.z = pts[0].z + pts[2].z;
    D2.x = D2.x - pts[1].x;
    D2.y = D2.y - pts[1].y;
    D2.z = D2.z - pts[1].z;
    D2.x = D2.x - pts[3].x;
    D2.y = D2.y - pts[3].y;
    D2.z = D2.z - pts[3].z;
    volatile float hy2 = D2.y * 0.5f;
    double L2 = sqrt((D2.z * 0.5f) * (D2.z * 0.5f) + (D2.x * 0.5f) * (D2.x * 0.5f));
    float roll;
    if (FAbs((float)L2) <= 1e-5f)
        roll = 0.0f;
    else
        roll = (float)atan(hy2 / L2);
    if (!(roll >= -s34)) {
        if (roll > s34)
            roll = s34;
        else
            roll = -s34;
    } else if (roll > s34) {
        roll = s34;
    }

    Vec3_18f6d0 np;
    np.x = pos.x;
    np.y = pos.y;
    np.z = pos.z;
    volatile float zp = vG.z * dt;
    np.x = np.x + vG.x * dt;
    np.y = np.y + vG.y * dt;
    np.z = np.z + zp;

    Matrix m1e0;
    m1e0.FUN_0022b980();
    m1e0.FUN_0022bab0(roll);
    Matrix m2a0;
    m2a0.FUN_0022b980();
    m2a0.FUN_0022ba30(pitch);
    Matrix m220;
    m220.FUN_0022b980();
    m220.FUN_0022ba70(ang);
    Matrix m260;
    m260.FUN_0022b980();
    m260.FUN_0022ca90(&m1e0, &m2a0);
    Matrix m1a0;
    m1a0.FUN_0022b980();
    m1a0.FUN_0022ca90(&m260, &m220);
    m1a0.m[12] = np.x;
    m1a0.m[13] = np.y;
    m1a0.m[14] = np.z;
    driver->xf.FUN_00221c60(&m1a0);
    cursor = (cursor + 1) % 4;
    return true;
}

} // namespace motion
} // namespace hulkfight
