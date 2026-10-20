// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 41/42, incomplete)
// hulkfight::motion::PropThrowAction::vfunc_4 @ 0x001841a0
#include "gen/hulkfight.h"

struct V3_1841a0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Cam_1841a0 {
    V3_1841a0 *FUN_001c39c0();
};
Cam_1841a0 *FUN_001c3d90();

struct Thing;

struct Params_1841a0 {
    char pad0[0x14];
    int f14;
    char b18;
    char pad19[3];
    V3_1841a0 v1c;
    float f28, f2c, f30, f34, f38, f3c, f40, f44;
    int i48;
    int i4c;
    int i50;
};

struct Link_1841a0 {
    int FUN_001d5e80(int v);
};

struct Sub70_1841a0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a);
    char pad04[0x98 - 4];
    V3_1841a0 v98;
};
struct Sub_1841a0 {
    char pad0[0x70];
    Sub70_1841a0 *p70;
};

struct Ent_1841a0 {
    char pad0[0x40];
    int f40;
    char pad44[0xec - 0x44];
    Link_1841a0 *link;
    Sub_1841a0 *FUN_001d72e0();
    V3_1841a0 *FUN_001d6b40();
    void FUN_001d8c70(Thing *t);
    int FUN_001d64a0();
    void FUN_001da350(int a, V3_1841a0 *b, V3_1841a0 *c, float d, Thing *e, float f, int g, float h, float i, float j, float k, float l, void *m);
    void FUN_001d71e0(int a);
};

struct Agent_1841a0 {
    char pad0[0x128];
    Ent_1841a0 *p128;
    int i12c;
    char pad130[0x328 - 0x130];
    Thing *p328;
    char pad32c[0x1f51 - 0x32c];
    char b1f51;
    char pad1f52[0x2064 - 0x1f52];
    V3_1841a0 v2064;
    char pad2070[0x20a8 - 0x2070];
    int i20a8;
    Ent_1841a0 *FUN_00035ef0(int slot);
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
    void FUN_00036c20(Sub_1841a0 *ev);
    float FUN_0003ec00(int a);
    float FUN_0003ebb0(int a);
    float FUN_000354c0();
};

struct Mid_1841a0 {
    Agent_1841a0 *FUN_00059a30();
};
struct Top_1841a0 {
    Mid_1841a0 *FUN_000592a0();
};

int FUN_00097a30(float a, float b, float c, Thing *t, int d, V3_1841a0 *pos, int e, V3_1841a0 *dir, int f, int g, int h, int i);
char FUN_00018960(float a, float b, float eps);
void FUN_00224d70(float angle, V3_1841a0 *v);
float FUN_00224f10(V3_1841a0 *v);

void hulkfight::motion::PropThrowAction::vfunc_4() {
    Agent_1841a0 *ag = (*(Top_1841a0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
    ag->b1f51 = 0;
    int slot = (*(Params_1841a0 * *)&this->f_1c)->f14;
    Ent_1841a0 *ent;
    if (slot < 0) {
        ent = ag->p128;
    } else {
        if (slot >= 8)
            return;
        ent = ag->FUN_00035ef0(slot);
    }
    if (!ent)
        return;
    Sub_1841a0 *ev = ent->FUN_001d72e0();
    if (!ev)
        return;
    ag->FUN_0003acf0(slot, 0, -1, 0, 0, 0);
    ag->FUN_00036c20(ev);
    float t;
    if (*((char *)(*(Params_1841a0 * *)&this->f_1c) + 0x80))
        t = ag->FUN_0003ec00(2);
    else
        t = ag->FUN_0003ebb0(2);
    volatile float tv = t;
    Params_1841a0 *q = (*(Params_1841a0 * *)&this->f_1c);
    float *qf = (float *)q;
    volatile float L0 = (qf[0x2c / 4] - qf[0x28 / 4]) * tv + qf[0x28 / 4];
    int hi = q->i4c;
    int lo = q->i48;
    volatile float L1 = (qf[0x34 / 4] - qf[0x30 / 4]) * tv + qf[0x30 / 4];
    volatile float L2 = (qf[0x3c / 4] - qf[0x38 / 4]) * tv + qf[0x38 / 4];
    volatile float L3 = (qf[0x44 / 4] - qf[0x40 / 4]) * tv + qf[0x40 / 4];
    int v = lo + (int)((hi - lo) * tv);
    volatile float L4 = (qf[0x58 / 4] - qf[0x54 / 4]) * tv + qf[0x54 / 4];
    Thing *th = ag->p328;
    volatile float L5 = (qf[0x60 / 4] - qf[0x5c / 4]) * tv + qf[0x5c / 4];
    float f = ag->FUN_000354c0();

    struct Frame {
        V3_1841a0 R;
        V3_1841a0 dir;
        V3_1841a0 pos;
        V3_1841a0 S;
        V3_1841a0 Z;
    } fr;
    Sub_1841a0 *ev2 = ent->FUN_001d72e0();
    Sub70_1841a0 *s70 = ev2->p70;
    fr.pos.x = 0;
    fr.pos.y = 0;
    fr.pos.z = 0;
    if (s70) {
        s70->v6(0);
        fr.pos.x = s70->v98.x;
        fr.pos.y = s70->v98.y;
        fr.pos.z = s70->v98.z;
    } else {
        V3_1841a0 *p = ent->FUN_001d6b40();
        fr.pos.x = p->x;
        fr.pos.y = p->y;
        fr.pos.z = p->z;
    }
    fr.dir.x = (*(Params_1841a0 * *)&this->f_1c)->v1c.x;
    fr.dir.y = (*(Params_1841a0 * *)&this->f_1c)->v1c.y;
    fr.dir.z = (*(Params_1841a0 * *)&this->f_1c)->v1c.z;
    FUN_00224d70(f, &fr.dir);
    if ((*(Params_1841a0 * *)&this->f_1c)->b18) {
        V3_1841a0 *o = FUN_001c3d90()->FUN_001c39c0();
        fr.dir.x = fr.dir.x + o->x;
        fr.dir.y = fr.dir.y + o->y;
        fr.dir.z = fr.dir.z + o->z;
    }
    fr.dir.FUN_0022d110();
    int i50 = (*(Params_1841a0 * *)&this->f_1c)->i50;
    if (FUN_00097a30(L1, L3, -1.0f, th, 0, &fr.pos, i50, &fr.dir, 0, 0, 0, 1))
        ent->FUN_001d8c70(th);
    fr.S.x = fr.dir.x * L1;
    fr.S.y = fr.dir.y * L1;
    fr.S.z = fr.dir.z * L1;
    int ety = ent->FUN_001d64a0();
    int kind = ent->link->FUN_001d5e80(ent->f40);
    if (ety == 5) {
        fr.R.x = -1.0f;
        fr.R.y = 0;
        fr.R.z = 0;
        if (ag->i20a8 >= 0) {
            fr.Z = ag->v2064;
            if (!(FUN_00018960(fr.Z.x, 0.0f, 1.0e-5f) && FUN_00018960(fr.Z.z, 0.0f, 1.0e-5f))) {
                FUN_00224d70(-f, &fr.Z);
                fr.R.x = -fr.Z.x;
            }
        }
        fr.R.x = fr.R.x * L2;
    } else {
        if (kind == 2 && hi > 0) {
            fr.R.x = 0;
            fr.R.y = -1.0f;
            fr.R.z = 0;
            float M = -1.0f;
            if (ag->i20a8 >= 0) {
                fr.Z = ag->v2064;
                if (FUN_00018960(fr.Z.x, 0.0f, 1.0e-5f)) {
                    M = fr.R.y;
                } else {
                    FUN_00224d70(-f, &fr.Z);
                    union { float f; unsigned int u; } a;
                    a.f = fr.Z.x;
                    a.u &= 0x7fffffff;
                    if (a.f < 0.5f) {
                        if (fr.Z.x < 0.0f)
                            M = -0.5f;
                        else
                            M = 0.5f;
                    } else {
                        M = fr.Z.x;
                    }
                }
            }
            fr.R.x = fr.R.x * L2;
            fr.R.y = M * L2;
            fr.R.z = fr.R.z * L2;
        } else {
            fr.R.x = -1.0f;
            fr.R.y = 0;
            fr.R.z = 0;
            if (ag->i20a8 >= 0) {
                fr.Z = ag->v2064;
                if (!(FUN_00018960(fr.Z.x, 0.0f, 1.0e-5f) && FUN_00018960(fr.Z.z, 0.0f, 1.0e-5f))) {
                    FUN_00224d70(-f, &fr.Z);
                    fr.R.x = fr.Z.z;
                    fr.R.y = fr.Z.x;
                }
            }
            fr.R.x = fr.R.x * L2;
            fr.R.y = fr.R.y * L2;
            fr.R.z = fr.R.z * L2;
        }
        float g = FUN_00224f10(&fr.dir);
        FUN_00224d70(g, &fr.R);
    }
    Params_1841a0 *q2 = (*(Params_1841a0 * *)&this->f_1c);
    ent->FUN_001da350(ag->i12c, &fr.S, &fr.R, L0, ag->p328, L3, v, t, L4, L5, *(float *)((char *)q2 + 0x64),
                      *(float *)((char *)q2 + 0x68), (char *)q2 + 0x78);
    ent->FUN_001d71e0(ag->i12c);
}
