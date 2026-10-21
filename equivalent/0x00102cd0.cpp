// STATUS: equivalent (tools/equiv.py level 3: 19936 inputs, branch coverage 50/50)
// CMoveAgent::vfunc_4 @ 0x00102cd0
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct V3_102cd0 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const V3_102cd0* other, float eps);
    float FUN_00018990();
};

class Body_102cd0 {
public:
    void FUN_00059a50(V3_102cd0* out);
};

class Agent_102cd0 {
public:
    char pad00[0x10];
    Body_102cd0* body;
    char pad14[0x2064 - 0x14];
    V3_102cd0 dir;
    float speed;
    V3_102cd0 aim;
    void FUN_00035550(V3_102cd0* v);
};

class Obj60_102cd0 {
public:
    char pad00[0x10];
    Body_102cd0* body;
    char pad14[0x1ca0 - 0x14];
    char* link;
};

class Item_102cd0 {
public:
    char pad[0x40];
    float x;
    char pad2[4];
    float z;
};

class Sub58_102cd0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Agent_102cd0* v6();
    virtual void v7();
    virtual void v8();
    virtual int v9();
    char pad04[0x60 - 4];
    Item_102cd0* item;
    char pad64[0xe8 - 0x64];
    char flagE8;
    int FUN_000fdc80();
    int FUN_000fdc40();
};

class Arg1_102cd0 {
public:
    char pad00[0x20];
    struct Gate_102cd0* gate;
};

struct Gate_102cd0 {
    char FUN_00024300(Agent_102cd0* a);
};

struct Env;
float FUN_0010ae50(Env* e, Agent_102cd0* a, float f, V3_102cd0* v1, V3_102cd0* v2, int zero, Obj60_102cd0** out);

extern Env* DAT_004dd700;
void FUN_00102bf0(Agent_102cd0* a, V3_102cd0* pos, float f, V3_102cd0* out);
void FUN_00102a50(Agent_102cd0* a, V3_102cd0* pos, V3_102cd0* out);

class CMoveAgent {
public:
    char pad00[0x58];
    Sub58_102cd0* sub;
    V3_102cd0 pos;
    char pad68[4];
    char flag6c;
    char pad6d[3];
    float f70;
    char flag74;
    char flag75;
    char flag76;
    void FUN_000fc550(Arg1_102cd0* a, int b, int c);
    void F(Arg1_102cd0* a, int b, int c);
};

void CMoveAgent::F(Arg1_102cd0* a1, int a2, int a3)
{
    V3_102cd0 A, B, C, D, F, G, H, J, E, w;
    V3_102cd0 junk;
    Obj60_102cd0* obj;
    float len, t, thr;
    char ok;

    FUN_000fc550(a1, a2, a3);
    Agent_102cd0* ag = sub->v6();
    A.x = 0; A.y = 0; A.z = 0;
    B.x = 0; B.y = 0; B.z = 0;
    C.x = 0; C.y = 0; C.z = 0;
    D.x = 0; D.y = 0; D.z = 0;
    if (sub && sub->v9() == 4)
        return;
    if (flag74)
        FUN_00102bf0(ag, &pos, 5.0f, &A);
    else
        FUN_00102a50(ag, &pos, &A);
    ok = a1->gate->FUN_00024300(ag);
    if (!ok)
        A.y = 0;
    len = (float)sqrt(A.z * A.z + A.x * A.x + A.y * A.y);
    A.FUN_0022d110();
    ag->body->FUN_00059a50(&junk);
    V3_102cd0 v80;
    v80.z = A.z;
    v80.x = A.x;
    v80.y = A.y;
    obj = 0;
    thr = 1.5f;
    if (!flag6c)
        thr = 0.99f;
    t = FUN_0010ae50(DAT_004dd700, ag, 1.5f, &v80, &B, 0, &obj);
    if (!(t < 0.0f) && !(t > thr) && !ok) {
        flag6c = 1;
    } else {
        flag6c = 0;
        B.z = 0;
        B.y = 0;
        B.x = 0;
    }
    flag76 = 0;
    int cnt80 = sub->FUN_000fdc80();
    int cnt40 = sub->FUN_000fdc40();
    if (cnt80 == cnt40) {
        E.x = 0; E.y = 0; E.z = 0;
        if (!B.FUN_0022d2b0(&E, 1.0e-5f)) {
            B.FUN_0022d110();
            F.x = A.x;
            F.y = 0;
            F.z = A.z;
            F.FUN_0022d110();
            if (F.z * B.z + F.x * B.x + B.y * F.y < -0.7f && t < 0.99f) {
                if (obj && obj->link && *(char**)(obj->link + 0x10c)) {
                    V3_102cd0* g = (V3_102cd0*)(*(char**)(obj->link + 0x10c) + 0x5c);
                    G = *g;
                    H.x = G.x - pos.x;
                    H.y = G.y - pos.y;
                    H.z = G.z - pos.z;
                    if (H.FUN_00018990() < 1.0f) {
                        obj->body->FUN_00059a50(&H);
                        ag->body->FUN_00059a50(&w);
                        F.x = G.x - H.x;
                        F.y = 0;
                        H.y = 0;
                        F.z = G.z - H.z;
                        H.x = pos.x - w.x;
                        H.z = pos.z - w.z;
                        hulk_freg lh = H.FUN_00018990();
                        hulk_freg lf = F.FUN_00018990();
                        if (lf < lh)
                            flag76 = 1;
                    }
                }
            } else {
                B.z = 0;
                B.y = 0;
                B.x = 0;
            }
        }
    }
    D.z = C.z + A.z;
    double sx = C.x + A.x;
    double sy = C.y + A.y;
    hulk_freg ty = B.y * 0.25f;
    hulk_freg tz = B.z * 0.25f;
    D.x = (float)(B.x * 0.25f + sx);
    D.y = (float)(ty + sy);
    D.z = tz + D.z;
    D.FUN_0022d110();
    if (flag76) {
        ag->speed = 0;
    } else if (sub->v9() >= 3 && !sub->flagE8) {
        ag->speed = 1.0f;
    } else if (len > f70) {
        ag->speed = f70;
    } else if (flag74) {
        ag->speed = len;
    } else {
        ag->speed = f70;
    }
    J.x = 0; J.y = 0; J.z = 0;
    if (D.FUN_0022d2b0(&J, 1.0e-5f)) {
        ag->FUN_00035550(&ag->aim);
    } else {
        Item_102cd0* item = sub->item;
        if (flag75 && item) {
            V3_102cd0 I;
            I.x = item->x;
            I.y = 0;
            I.z = item->z;
            ag->body->FUN_00059a50(&w);
            J.x = I.x - w.x;
            J.y = 0;
            J.z = I.z - w.z;
            J.FUN_0022d110();
            ag->aim.x = J.x;
            ag->aim.y = J.y;
            ag->aim.z = J.z;
        } else {
            ag->aim.x = A.x;
            ag->aim.y = A.y;
            ag->aim.z = A.z;
        }
    }
    ag->dir.x = D.x;
    ag->dir.y = D.y;
    ag->dir.z = D.z;
}
