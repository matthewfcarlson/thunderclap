// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 56/56)
// CHand2HandAgent::vfunc_4 @ 0x00102590
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" double sqrt(double);
extern char DAT_004a1bfc;

struct RandState {
    float FUN_00078780();
};
RandState *__cdecl FUN_000964d0();

struct V3 {
    float x;
    float y;
    float z;
};

struct Sub {
    char pad[0x10c];
    V3 v;
};

struct Player {
    char pad0[0x1cd8];
    float lo;
    float hi;
    char pad1ce0[0x1f58 - 0x1ce0];
    Sub sub;
};

class Ctrl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Player *v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
};

class CHand2HandAgent {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4(int a0, float dt, int a2);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual char v12(Player *pl);
    virtual void v13();
    virtual void v14(int a0, float dt);
    virtual char v15(int a0, Player *pl);
    virtual void v16();
    virtual char v17(Sub *sub, float dt);
    virtual void v18();
    virtual void v19();
    virtual void v20(Player *pl, Sub *sub, float dt);
    virtual void v21(Player *pl, Sub *sub, float dt);
    virtual void v22(Player *pl, Sub *sub, float dt);
    virtual void v23(Player *pl, Sub *sub, float dt);
    char pad04[0x58 - 4];
    Ctrl *ctrl;
    char pad5c[4];
    char b60;
    char pad61[3];
    float f64;
    float f68;
    char pad6c[4];
    float f70;
    char pad74[0x79 - 0x74];
    char b79;
    char pad7a[0x7e - 0x7a];
    char b7e;
    char b7f;
    float f80;
    float f84;
    char pad88[0xb0 - 0x88];
    V3 dirA;
    V3 dirB;
    float fc8;
    char bcc;
    char padcd[0xd1 - 0xcd];
    char bd1;
    char bd2;
    char bd3;
    float fd4;
    float fd8;
    float fdc;
    float fe0;
    char pade4[0x138 - 0xe4];
    V3 w0;
    V3 w1;
    V3 w2;
    V3 w3;
    V3 w4;
    V3 va;
    float f180;
    V3 vb;
    int f190;
    V3 cur;

    void FUN_000fc550(int a0, float dt, int a2);
};

void CHand2HandAgent::vfunc_4(int a0, float dt, int a2)
{
    unsigned int cookie = DAT_004d9968;
    FUN_000fc550(a0, dt, a2);
    if ((char)a2) {
        va.x = va.y = va.z = 0.0f;
        vb.x = vb.y = vb.z = 0.0f;
    }
    RandState *rng = FUN_000964d0();
    Player *pl = ctrl->v6();
    Sub *sub = &pl->sub;
    if (ctrl) {
        if (ctrl->v9() == 4) {
            __security_check_cookie(cookie);
            return;
        }
    }
    v14(a0, dt);
    if (!bd1) {
        bd1 = v17(sub, dt);
        if (!bd1) {
            double x = f64 - dt;
            f64 = (float)x;
            float dot = dirB.z * dirA.z + dirB.y * dirA.y + dirB.x * dirA.x;
            if (dot > 0.75f)
                f64 = (float)(x - dt);
            if (b60)
                f64 = f64 - dt;
        }
    }
    f70 = f70 - dt;
    f68 = dt + f68;
    f80 = f80 - dt;
    double s = dt + f84;
    f84 = (float)s;
    if (s > 10.0)
        f84 = 10.0f;
    v19();
    w0.z = w0.y = w0.x = 0.0f;
    w1.z = w1.y = w1.x = 0.0f;
    w2.z = w2.y = w2.x = 0.0f;
    w3.z = w3.y = w3.x = 0.0f;
    w4.z = w4.y = w4.x = 0.0f;
    char t = 0;
    if (bd2)
        t = v15(a0, pl);
    if (!bd1 && !bd3 && bcc)
        bd1 = v12(pl);
    if (t) {
        v20(pl, sub, dt);
        f190 = 0;
    } else if ((fc8 < fd4) || (fc8 > fd8) || (b7f && !DAT_004a1bfc)) {
        if (fc8 > fd8 + 3.0f)
            b79 = 1;
        v21(pl, sub, dt);
        f190 = 1;
    } else if ((fc8 < fdc) || (fc8 > fe0) || (b7e && !DAT_004a1bfc)) {
        v22(pl, sub, dt);
        f190 = 2;
    } else {
        if (b79) {
            if (f64 <= 0.0f) {
                float lo = pl->lo;
                float hi = pl->hi;
                f64 = rng->FUN_00078780() * (hi - lo) + lo;
            }
            b79 = 0;
        }
        v23(pl, sub, dt);
        f190 = 3;
    }
    double lenA = sqrt(cur.x * cur.x + cur.y * cur.y + cur.z * cur.z);
    if (lenA > 0.1f) {
        double lenB = sqrt(sub->v.x * sub->v.x + sub->v.y * sub->v.y + sub->v.z * sub->v.z);
        if (lenB > 0.1f) {
            double d1 = sub->v.z * cur.z + sub->v.y * cur.y + cur.x * sub->v.x;
            if (d1 < -0.7f) {
                union {
                    float f;
                    unsigned int u;
                } d2;
                d2.f = sub->v.z * dirB.z + sub->v.y * dirB.y + sub->v.x * dirB.x;
                d2.u &= 0x7fffffff;
                if (d2.f < 0.2f) {
                    cur.x = sub->v.x;
                    cur.y = sub->v.y;
                    cur.z = sub->v.z;
                }
            }
        }
    }
    cur.x = sub->v.x;
    cur.y = sub->v.y;
    cur.z = sub->v.z;
    __security_check_cookie(cookie);
}
