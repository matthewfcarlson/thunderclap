// STATUS: equivalent (tools/equiv.py level 3: 3031 inputs, branch coverage 65/68, incomplete)
// hulkfight::motion::JointTrackerAction::vfunc_5 @ 0x001734b0
#include "decls/data/game/hulkfight/motion.h"

extern "C" int __cdecl _isnan(double d);
extern "C" double fabs(double);

struct V3_1734b0 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3_1734b0 *a, const V3_1734b0 *b);
};

struct Mat_1734b0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_1734b0 *axis, float angle);
    void FUN_0022c3b0(const V3_1734b0 *in, V3_1734b0 *out);
    void FUN_0022ca90(Mat_1734b0 *a, Mat_1734b0 *b);
    void FUN_0022bec0(const V3_1734b0 *a, const V3_1734b0 *b);
    void FUN_0022c0b0();
};

struct A24;
struct Part8 {
    void FUN_000350c0(V3_1734b0 *out);
    void FUN_00035020(V3_1734b0 *out);
};

struct Obj2c {
    void FUN_0022c2b0(float *w, V3_1734b0 *t);
};

struct Obj11c_1734b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual char *v8();
};

struct Body5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Obj2c *v15();
    char pad04[0x11c - 4];
    Obj11c_1734b0 *f11c;
    char pad120[0x148 - 0x120];
    Part8 *f148;
};

struct Obj74 {
    virtual void v0();
    virtual void v1();
    char pad04[4];
    void *f8;
    int fc;
    char pad10[0x40 - 0x10];
    float f40, f44, f48;
};

struct R8 {
    char pad0[0x28];
    unsigned short *f28;
};
struct Q64 {
    char pad0[8];
    R8 *f8;
    char pad0c[0x1c - 0xc];
    Mat_1734b0 *f1c;
};

struct YObj_1734b0 {
    Obj74 *FUN_0003ffe0(float a, float b, int flag, Obj74 *old, V3_1734b0 *out);
    float FUN_000354c0();
};

struct ZObj {
    char pad0[0x64];
    Q64 *f64;
    void FUN_00222970(struct A24 *a, int b);
    void FUN_00222890(struct A24 *a, float b, float c, float d, float e, float f, float g);
};

struct XObj_1734b0 {
    YObj_1734b0 *FUN_00059a30();
    ZObj *FUN_00059a40();
};

struct F20_1734b0 {
    XObj_1734b0 *FUN_000592a0();
};

struct Sub18_1734b0 {
    void FUN_00221c60(Mat_1734b0 *m);
};

struct A24 {
    char pad0[0x10];
    int f10;
    char pad14[4];
    Sub18_1734b0 sub18;
};

struct P1c_1734b0 {
    char pad0[0x38];
    float f38;
    float f3c;
    float f40;
    float f44;
    float f48;
    char b4c;
    char pad4d[3];
    float f50;
    float f54;
    int f58;
    float f5c;
    float f60;
    float f64;
};


float __cdecl FUN_00018a20(float v);
float __cdecl FUN_000189c0(float v);
float __cdecl FUN_00224ea0(float a, float b);
float __cdecl FUN_00224fc0(float a, float b);
void __cdecl FUN_00224d70(float angle, V3_1734b0 *v);

struct Frame_1734b0 {
    float s0;           // 0x00
    float s4;           // 0x04
    V3_1734b0 V;               // 0x08
    union {
        char b;
        int i;
        float f;
    } fl;               // 0x14
    V3_1734b0 T;               // 0x18
    ZObj *Zs;           // 0x24
    V3_1734b0 U;               // 0x28
    V3_1734b0 W;               // 0x34
    float W3;           // 0x40
    V3_1734b0 R;               // 0x44
    V3_1734b0 Q;               // 0x50
    int idx;            // 0x5c
    YObj_1734b0 *Ys;           // 0x60
    Q64 *Qs;            // 0x64
    Mat_1734b0 A;              // 0x68
    Mat_1734b0 B;              // 0xa8
    Mat_1734b0 C;              // 0xe8
    Mat_1734b0 D;              // 0x128
    Mat_1734b0 F;              // 0x168
    Mat_1734b0 G;              // 0x1a8
};

class JointTrackerAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool v5(int a0, float dt);
    char pad04[0x1c - 4];
    P1c_1734b0 *p1c;
    F20_1734b0 *p20;
    A24 *p24;
    V3_1734b0 v28;
    Mat_1734b0 m34;
    Obj74 *f74;
};

bool JointTrackerAction::v5(int a0, float dt)
{
    Frame_1734b0 f;
    Obj74 *obj;
    float pitch;

    if (a0)
        return true;
    XObj_1734b0 *X = p20->FUN_000592a0();
    YObj_1734b0 *Y = X->FUN_00059a30();
    f.Ys = Y;
    ZObj *Z = X->FUN_00059a40();
    Q64 *edi = Z->f64;
    f.Zs = Z;
    f.s0 = p1c->f50;
    f.s4 = p1c->f54;
    f.fl.b = p1c->b4c;
    f.Qs = edi;
    obj = Y->FUN_0003ffe0(f.s0, f.s4, f.fl.i, f74, &f.U);
    if (obj)
        obj->v0();
    if (f74)
        f74->v1();
    f74 = obj;

    f.idx = p24->f10;
    f.C = edi->f1c[f.idx];
    f.R.x = f.C.m[12];
    f.R.y = f.C.m[13];
    f.R.z = f.C.m[14];
    f.T.x = 0.0f;
    f.T.y = 0.0f;
    f.T.z = 0.0f;
    if (obj == 0) {
        if (p1c->b4c) {
            Z->FUN_00222970(p24, 0);
            return true;
        }
        f.s0 = f.U.FUN_0022d110();
        f.s0 = (float)fabs(f.s0);
        if (f.s0 <= 1e-5f) {
            Z->FUN_00222970(p24, 0);
            return true;
        }
        goto L298;
    }
    f.T.x = obj->f40;
    f.T.y = obj->f44;
    f.T.z = obj->f48;
    {
        int kind = obj->fc;
        int mode = p1c->f58;
        if (kind == 1) {
            Part8 *p = (Part8 *)obj->f8;
            if (mode == 1)
                p->FUN_000350c0(&f.T);
            else if (mode == 2)
                p->FUN_00035020(&f.T);
        } else if (kind == 5) {
            Body5 *b = (Body5 *)obj->f8;
            if (b != 0) {
                Part8 *o148 = b->f148;
                if (o148 != 0) {
                    if (mode == 1)
                        o148->FUN_000350c0(&f.T);
                    else if (mode == 2)
                        o148->FUN_00035020(&f.T);
                } else if (mode == 2 || mode == 1) {
                    Obj11c_1734b0 *o11c = b->f11c;
                    if (o11c != 0) {
                        char *r = o11c->v8();
                        if (r != 0) {
                            f.W.x = *(float *)(r + 0x2c);
                            f.W.y = *(float *)(r + 0x30);
                            f.W.z = *(float *)(r + 0x34);
                            f.W3 = *(float *)(r + 0x38);
                            b->v15()->FUN_0022c2b0((float *)&f.W, &f.T);
                        }
                    }
                }
            }
        }
    }
    if (_isnan(f.T.x) || _isnan(f.T.y) || _isnan(f.T.z)
        || fabs(f.T.x) >= 5000.0f || fabs(f.T.y) >= 5000.0f || fabs(f.T.z) >= 5000.0f) {
        if (f74) {
            f74->v1();
            f74 = 0;
        }
        if (p1c->b4c) {
            Z->FUN_00222970(p24, 0);
            return true;
        }
        f.s0 = f.U.FUN_0022d110();
        f.s0 = (float)fabs(f.s0);
        if (f.s0 <= 1e-5f) {
            Z->FUN_00222970(p24, 0);
            return true;
        }
    } else {
        f.U.x = f.T.x - f.R.x;
        f.U.y = f.T.y - f.R.y;
        f.U.z = f.T.z - f.R.z;
        f.U.FUN_0022d110();
    }
L298:
    f.C.FUN_0022c3b0(&v28, &f.Q);
    f.s4 = p1c->f38;
    if (f.s4 <= 0.0f) {
        f.V.x = f.U.x;
        f.V.y = f.U.y;
        f.V.z = f.U.z;
    } else {
        double dotd = f.Q.z * f.U.z + f.Q.y * f.U.y + f.Q.x * f.U.x;
        f.s0 = (float)dotd;
        float ang;
        if (dotd >= 1.0f)
            ang = 0.0f;
        else if (f.s0 <= -1.0f)
            ang = 3.1415927410125732f;
        else
            ang = FUN_00018a20(f.s0);
        f.s4 = f.s4 * dt;
        if (ang <= f.s4) {
            f.V.x = f.U.x;
            f.V.y = f.U.y;
            f.V.z = f.U.z;
        } else {
            f.W.FUN_000111b0(&f.U, &f.Q);
            f.A.FUN_0022baf0(&f.W, f.s4);
            f.A.FUN_0022c3b0(&f.Q, &f.V);
        }
    }
    pitch = FUN_000189c0(f.V.y);
    f.s0 = pitch;
    f.s4 = p1c->f3c;
    f.fl.f = p1c->f40;
    if (pitch < f.s4) {
        f.A.FUN_0022b980();
        f.R.z = -f.V.x;
        f.R.x = f.V.z;
        f.R.y = 0.0f;
        f.A.FUN_0022baf0(&f.R, f.s4 - f.s0);
        f.W.x = f.V.x;
        f.W.y = f.V.y;
        f.W.z = f.V.z;
        f.A.FUN_0022c3b0(&f.W, &f.V);
    } else if (f.s0 > f.fl.f) {
        f.A.FUN_0022b980();
        f.W.z = -f.V.x;
        f.W.x = f.V.z;
        f.W.y = 0.0f;
        f.A.FUN_0022baf0(&f.W, f.fl.f - f.s0);
        f.R.x = f.V.x;
        f.R.y = f.V.y;
        f.R.z = f.V.z;
        f.A.FUN_0022c3b0(&f.R, &f.V);
    }
    f.fl.f = FUN_00224ea0(f.V.x, f.V.z);
    f.s0 = Y->FUN_000354c0();
    float diff = FUN_00224fc0(f.s0, f.fl.f);
    f.fl.f = p1c->f44;
    f.s4 = p1c->f48;
    {
        bool rot = false;
        double val = 0.0;
        if (diff < f.fl.f) {
            val = f.fl.f;
            rot = true;
        } else if (diff > f.s4) {
            val = f.s4;
            rot = true;
        }
        if (rot) {
            f.V.z = (*(float*)&DAT_004b7d20);
            f.V.x = (*(float*)&DAT_004b7d18);
            FUN_00224d70((float)(val + f.s0), &f.V);
            f.V.FUN_0022d110();
        }
    }
    f.D.FUN_0022b980();
    f.W.x = 0.0f;
    f.W.y = 1.0f;
    f.W.z = 0.0f;
    f.D.FUN_0022bec0(&f.V, &f.W);
    f.F.FUN_0022ca90(&m34, &f.D);
    {
        Q64 *q = f.Qs;
        f.B = q->f1c[q->f8->f28[f.idx]];
    }
    f.B.m[14] = 0.0f;
    f.B.m[13] = 0.0f;
    f.B.m[12] = 0.0f;
    f.B.FUN_0022c0b0();
    f.G.FUN_0022ca90(&f.F, &f.B);
    p24->sub18.FUN_00221c60(&f.G);
    f.Zs->FUN_00222890(p24, -1.0f, p1c->f5c, 1.0f, p1c->f60, p1c->f64, -1.0f);
    return true;
}
