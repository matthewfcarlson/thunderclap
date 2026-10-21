// STATUS: equivalent (tools/equiv.py level 3: 20058 inputs, branch coverage 64/64)
// CHeadTrackerAction::vfunc_7 @ 0x000202f0
#include "decls/data/game/global.h"
#include "compat/ptr.h"

extern "C" int __cdecl _isnan(double d);

struct V3_202f0 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_000111b0(const V3_202f0 *a, const V3_202f0 *b);
};

struct V4_202f0 { float x, y, z, w; };

struct Mat4_202f0 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(const V3_202f0 *axis, float angle);
    void FUN_0022c3b0(const V3_202f0 *in, V3_202f0 *out);
    void FUN_0022c2b0(const V4_202f0 *a, V3_202f0 *b);
    void FUN_0022bec0(const V3_202f0 *fwd, const V3_202f0 *up);
    void FUN_0022ca90(const Mat4_202f0 *a, const Mat4_202f0 *b);
    void FUN_0022c0b0();
    void FUN_0022cc10(const Mat4_202f0 *a, const Mat4_202f0 *b);
};

struct Xf_202f0 {
    char data[16];
    void FUN_0022b370(const Mat4_202f0 *m);
};

struct Part18_202f0 {
    void FUN_00221cf0(const Xf_202f0 *x);
};

struct Obj1_202f0 {
    void FUN_00035020(V3_202f0 *out);
};

struct Q2 {
    char pad0[0x2c];
    V4_202f0 f2c;
};

struct Aux3 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual Q2 *v8();
};

struct Obj2_202f0 {
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3();
    virtual void o4(); virtual void o5(); virtual void o6(); virtual void o7();
    virtual void o8(); virtual void o9(); virtual void o10(); virtual void o11();
    virtual void o12(); virtual void o13(); virtual void o14();
    virtual Mat4_202f0 *v15();
    char pad_o[0x11c - 0x4];
    Aux3 *f11c;
    char pad120[0x148 - 0x120];
    Obj1_202f0 *f148;
};

struct Target_202f0 {
    virtual void ref();
    virtual void unref();
    char pad4[4];
    union {
        Obj1_202f0 *o1;
        Obj2_202f0 *o2;
    } u08;                           // 8
    int f0c;
    char pad10[0x40 - 0x10];
    V3_202f0 v40;
};

struct Bone_202f0 {
    char pad0[0x28];
    unsigned short *parent;          // 0x28
};

struct YBlk {
    char pad0[8];
    Bone_202f0 *f8;
    char pad0c[0x1c - 0xc];
    Mat4_202f0 *f1c;
};

struct CfgA {
    char pad0[0x38];
    float f38, f3c, f40, f44, f48;
    int f4c, f50;
    float f54, f58, f5c;
};

struct CfgB {
    char pad0[0x10];
    int f10;
    char pad14[0x18 - 0x14];
    Part18_202f0 part18;
};

struct XBlk {
    char pad0[0x64];
    YBlk *f64;
    void FUN_00222970(CfgB *c, int z);
    void FUN_00222890(CfgB *c, float a, float b, float d, float e, float f, float g);
};

struct Aux4 {
    char pad0[0x12c];
    Target_202f0 *f12c;
};

struct Fighter_202f0 {
    char pad0[0x328];
    Target_202f0 *f328;
    unsigned char b32c;
    char pad32d[0x334 - 0x32d];
    Aux4 *f334;
    void FUN_00035dc0(V3_202f0 *out);
    char FUN_0003a440(V3_202f0 *a, V3_202f0 *b, int lo, int hi, Target_202f0 *t);
    Target_202f0 *FUN_00039c60(V3_202f0 *a, V3_202f0 *b, int lo, int hi, int p, int q, int r);
    float FUN_000354c0();
};

struct Anchor_202f0 {
    Fighter_202f0 *FUN_00059a30();
    XBlk *FUN_00059a40();
};

struct Owner_202f0 {
    Anchor_202f0 *FUN_000592a0();
};

float __cdecl FUN_00018a20(float v);
float __cdecl FUN_000189c0(float v);
float __cdecl FUN_00224ea0(float a, float b);
float __cdecl FUN_00224fc0(float a, float b);
void __cdecl FUN_00224d70(float a, V3_202f0 *v);

union FS_202f0 {
    float f;
    int i;
};

struct Frame_202f0 {
    FS_202f0 s10;                          // S+0x10
    FS_202f0 s14;                          // 0x14
    V3_202f0 v18;                          // 0x18
    FS_202f0 s24;                          // 0x24
    V3_202f0 v28;                          // 0x28
    V3_202f0 t34;                          // 0x34
    union {
        struct {
            V3_202f0 v40;                  // 0x40
            int s4c;                       // 0x4c
        } a;
        V4_202f0 w;                        // 0x40: the quaternion copied for FUN_0022c2b0
    } u40;
    XBlk *X;                         // 0x50
    V3_202f0 boneT;                        // 0x54
    YBlk *Y;                         // 0x60
    V3_202f0 v64;                          // 0x64
    V3_202f0 v70;                          // 0x70
    int bone;                        // 0x7c
    Mat4_202f0 m80;                        // 0x80
    Mat4_202f0 mc0;                        // 0xc0
    Mat4_202f0 m100;                       // 0x100
    Mat4_202f0 m140;                       // 0x140
    Mat4_202f0 m180;                       // 0x180
};

class CHeadTrackerAction {
public:
    virtual void h0(); virtual void h1(); virtual void h2(); virtual void h3();
    virtual void h4(); virtual void h5(); virtual void h6();
    virtual char vfunc_7(float dt);
    char pad04[0x1c - 0x4];
    Owner_202f0 *f1c;
    CfgA *f20;
    CfgB *f24;
    V3_202f0 v28;
    Mat4_202f0 m34;
    unsigned char b74;
    char pad75[3];
    Xf_202f0 xf78;
    Target_202f0 *f88;
    unsigned int f8c;
};

char CHeadTrackerAction::vfunc_7(float dt)
{
    Frame_202f0 f;
    Anchor_202f0 *an = f1c->FUN_000592a0();
    Fighter_202f0 *F = an->FUN_00059a30();
    f.X = an->FUN_00059a40();
    f8c = f8c + 1;
    f.Y = f.X->f64;
    f.bone = f24->f10;
    Mat4_202f0 *bm = &f.Y->f1c[f.bone];
    f.boneT.x = bm->m[12];
    f.boneT.y = bm->m[13];
    f.boneT.z = bm->m[14];
    F->FUN_00035dc0(&f.v28);

    Target_202f0 *tgt;
    bool have = false;
    if (F->b32c == 0) {
        tgt = F->f328;
        if (F->FUN_0003a440(&f.boneT, &f.v28, f20->f4c, f20->f50, tgt))
            have = true;
    } else {
        tgt = F->f328;
        have = true;
    }
    if (!(have && tgt != 0)) {
        bool found = false;
        if (F->f334 != 0) {
            tgt = F->f334->f12c;
            if (F->FUN_0003a440(&f.boneT, &f.v28, f20->f4c, f20->f50, tgt) && tgt != 0)
                found = true;
        }
        if (!found) {
            tgt = f88;
            if (!F->FUN_0003a440(&f.boneT, &f.v28, f20->f4c, f20->f50, tgt)) {
                tgt = 0;
            } else if (tgt != 0) {
                found = true;
            }
            if (!found) {
                if (f8c % 10 == 0)
                    tgt = F->FUN_00039c60(&f.boneT, &f.v28, f20->f4c, f20->f50, 0, 0, 0);
            }
        }
    }
    if (tgt != 0)
        tgt->ref();
    if (f88 != 0)
        f88->unref();
    f88 = tgt;
    if (tgt == 0) {
        f.X->FUN_00222970(f24, 0);
        return 1;
    }

    f.t34 = tgt->v40;
    if (tgt->f0c == 1) {
        tgt->u08.o1->FUN_00035020(&f.t34);
    } else if (tgt->f0c == 5) {
        Obj2_202f0 *o2 = tgt->u08.o2;
        if (o2 != 0) {
            if (o2->f148 != 0) {
                o2->f148->FUN_00035020(&f.t34);
            } else if (o2->f11c != 0) {
                Q2 *q = o2->f11c->v8();
                if (q != 0) {
                    f.u40.w = q->f2c;
                    o2->v15()->FUN_0022c2b0(&f.u40.w, &f.t34);
                }
            }
        }
    }

    bool bad = false;
    if (_isnan(f.t34.x) || _isnan(f.t34.y) || _isnan(f.t34.z)) {
        bad = true;
    } else {
        f.s10.f = f.t34.x;
        f.s10.i &= 0x7fffffff;
        if (f.s10.f >= 5000.0f) {
            bad = true;
        } else {
            f.s10.f = f.t34.y;
            f.s10.i &= 0x7fffffff;
            if (f.s10.f >= 5000.0f) {
                bad = true;
            } else {
                f.s10.f = f.t34.z;
                f.s10.i &= 0x7fffffff;
                if (f.s10.f >= 5000.0f)
                    bad = true;
            }
        }
    }
    if (bad) {
        if (f88 != 0) {
            f88->unref();
            f88 = 0;
        }
        f.X->FUN_00222970(f24, 0);
        return 1;
    }

    f.v28.x = f.t34.x - f.boneT.x;
    f.v28.y = f.t34.y - f.boneT.y;
    f.v28.z = f.t34.z - f.boneT.z;
    f.v28.FUN_0022d110();
    f.Y->f1c[f.bone].FUN_0022c3b0(&v28, &f.v70);
    CfgA *cfg = f20;
    if (cfg->f38 > 0.0f || cfg->f38 != cfg->f38) {
        f.s24.f = FUN_00018a20(f.v70.z * f.v28.z + f.v70.y * f.v28.y + f.v70.x * f.v28.x);
        f.s14.f = dt * cfg->f38;
        f.s10.f = f.s24.f;
        f.s10.i &= 0x7fffffff;
        if (f.s10.f <= f.s14.f) {
            f.v18 = f.v28;
        } else {
            f.u40.a.v40.FUN_000111b0(&f.v28, &f.v70);
            if (f.s24.f < 0.0f)
                f.m80.FUN_0022baf0(&f.u40.a.v40, -f.s14.f);
            else
                f.m80.FUN_0022baf0(&f.u40.a.v40, f.s14.f);
            f.m80.FUN_0022c3b0(&f.v70, &f.v18);
        }
    } else {
        f.v18 = f.v28;
    }

    f.s10.f = FUN_000189c0(f.v18.y);
    cfg = f20;
    if (f.s10.f < cfg->f3c) {
        f.s24.f = cfg->f3c;
        f.m80.FUN_0022b980();
        f.v64.x = f.v18.z;
        f.v64.y = 0.0f;
        f.v64.z = -f.v18.x;
        f.m80.FUN_0022baf0(&f.v64, f.s24.f - f.s10.f);
        f.u40.a.v40 = f.v18;
        f.m80.FUN_0022c3b0(&f.u40.a.v40, &f.v18);
    } else if (f.s10.f > cfg->f40) {
        f.s24.f = cfg->f40;
        f.m80.FUN_0022b980();
        f.u40.a.v40.x = f.v18.z;
        f.u40.a.v40.y = 0.0f;
        f.u40.a.v40.z = -f.v18.x;
        f.m80.FUN_0022baf0(&f.u40.a.v40, f.s24.f - f.s10.f);
        f.v64 = f.v18;
        f.m80.FUN_0022c3b0(&f.v64, &f.v18);
    }

    f.s24.f = FUN_00224ea0(f.v18.x, f.v18.z);
    f.s14.f = F->FUN_000354c0();
    hulk_freg diff = FUN_00224fc0(f.s14.f, f.s24.f);
    cfg = f20;
    if (diff < cfg->f44) {
        f.v18.x = (*(float*)&DAT_0048e054);
        f.v18.z = (*(float*)((char*)&DAT_0048e054 + 8));
        FUN_00224d70(f.s14.f + cfg->f44, &f.v18);
    } else if (diff > cfg->f48) {
        f.v18.x = (*(float*)&DAT_0048e054);
        f.v18.z = (*(float*)((char*)&DAT_0048e054 + 8));
        FUN_00224d70(f.s14.f + cfg->f48, &f.v18);
    }

    f.mc0.FUN_0022b980();
    f.u40.a.v40.x = 0.0f;
    f.u40.a.v40.y = 1.0f;
    f.u40.a.v40.z = 0.0f;
    f.mc0.FUN_0022bec0(&f.v18, &f.u40.a.v40);
    f.m140.FUN_0022ca90(&m34, &f.mc0);
    f.m100 = f.Y->f1c[f.Y->f8->parent[f.bone]];
    f.m100.FUN_0022c0b0();
    f.m180.FUN_0022cc10(&f.m140, &f.m100);
    b74 = 1;
    xf78.FUN_0022b370(&f.m180);
    f24->part18.FUN_00221cf0(&xf78);
    cfg = f20;
    f.X->FUN_00222890(f24, -1.0f, cfg->f54, 1.0f, cfg->f58, cfg->f5c, -1.0f);
    return 1;
}
