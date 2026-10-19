// STATUS: equivalent (tools/equiv.py level 3: 5700 inputs, branch coverage 20/20)
// CBlendCamera::vfunc_35 @ 0x000985b0
// cl-flags: /GS

struct Vec3_985b0 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bec0(Vec3_985b0 *pos, Vec3_985b0 *up);
    void FUN_0022bab0(float angle);
    void FUN_0022ca90(Matrix *a, Matrix *b);
    void FUN_0022be40(Vec3_985b0 *pos);
};

struct CamState {
    float f[10];
};

float FUN_000a02a0(float angle);
void FUN_0009f8c0(Vec3_985b0 *out, float a, float b, float c);

class CGameCamera {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(float v);
    virtual void vfunc_8();
    virtual void vfunc_9(float v);
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
    virtual void vfunc_21(Matrix *m);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35(int a1, float a2, int a3, int a4);
    virtual void vfunc_36();
    virtual void vfunc_37();
    char pad04[0x170 - 4];
    CGameCamera *camA;
    CGameCamera *camB;
    char blendA;
    char pad179[3];
    float time;
    CamState stateA;
    int mode;
    int ease;
    float duration;
};

class CBlendCamera : public CGameCamera {
public:
    virtual void vfunc_35(int a1, float a2, int a3, int a4);
    void FUN_00098500(CGameCamera *cam, CamState *out);
    void FUN_000a9090(float v);
};

void CBlendCamera::vfunc_35(int a1, float a2, int a3, int a4)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if (blendA) {
        camA->vfunc_35(a1, a2, 0, 0);
        FUN_00098500(camA, &stateA);
    }
    camB->vfunc_35(a1, a2, 0, 0);
    CamState b;
    FUN_00098500(camB, &b);
    float t = a2 + time;
    float k = 0.0f;
    time = t;
    if (mode == 0) {
        k = 1.0f;
    } else if (mode == 1) {
        float u = t / duration;
        if (!(u >= 0.0f)) {
            u = 0.0f;
        } else if (u > 1.0f) {
            u = 1.0f;
        }
        if (ease == 1) {
            k = u * u;
        } else if (ease == 2) {
            k = (u + u) - u * u;
        } else if (ease == 3) {
            k = (3.0f - (u + u)) * u * u;
        } else {
            k = u;
        }
    }
    CamState r;
    r.f[0] = (b.f[0] - stateA.f[0]) * k + stateA.f[0];
    r.f[1] = (b.f[1] - stateA.f[1]) * k + stateA.f[1];
    r.f[2] = (b.f[2] - stateA.f[2]) * k + stateA.f[2];
    r.f[3] = FUN_000a02a0(b.f[3] - stateA.f[3]) * k + stateA.f[3];
    r.f[3] = FUN_000a02a0(r.f[3]);
    r.f[4] = (b.f[4] - stateA.f[4]) * k + stateA.f[4];
    r.f[5] = (b.f[5] - stateA.f[5]) * k + stateA.f[5];
    r.f[6] = (b.f[6] - stateA.f[6]) * k + stateA.f[6];
    r.f[7] = (b.f[7] - stateA.f[7]) * k + stateA.f[7];
    r.f[8] = (b.f[8] - stateA.f[8]) * k + stateA.f[8];
    r.f[9] = (b.f[9] - stateA.f[9]) * k + stateA.f[9];

    Vec3_985b0 p;
    FUN_0009f8c0(&p, r.f[3], r.f[4], r.f[5]);
    Matrix m1;
    m1.FUN_0022b980();
    Vec3_985b0 up;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    Vec3_985b0 negP;
    negP.x = -p.x;
    negP.y = -p.y;
    negP.z = -p.z;
    m1.FUN_0022bec0(&negP, &up);
    if (r.f[6] != 0.0f) {
        Matrix m2;
        m2.FUN_0022b980();
        m2.FUN_0022bab0(r.f[6]);
        Matrix m3;
        m3.FUN_0022ca90(&m2, &m1);
        m1 = m3;
    }
    Vec3_985b0 q;
    q.x = p.x + r.f[0];
    q.y = p.y + r.f[1];
    q.z = p.z + r.f[2];
    m1.FUN_0022be40(&q);
    vfunc_21(&m1);
    FUN_000a9090(r.f[7]);
    vfunc_7(r.f[8]);
    vfunc_9(r.f[9]);
    CGameCamera::vfunc_35(a1, a2, a3, a4);
}
