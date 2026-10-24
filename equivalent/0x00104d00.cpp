// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 21/22, incomplete)
// CPathGraphAgent::vfunc_4 @ 0x00104d00
#include "gen/global.h"

#include "decls/data/game/global.h"

struct V3_104d00 {
    float x, y, z;
    float FUN_0022d110();
};

struct Mode_104d00 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int vfunc_9();
};

struct Agent_104d00 {
    char pad0[0x1a60];
    V3_104d00 pos;                 // 0x1a60
    char pad1a6c[0x1ca0 - 0x1a6c];
    Mode_104d00 *mode;             // 0x1ca0
    char pad1ca4[0x2064 - 0x1ca4];
    V3_104d00 out1;                // 0x2064
    float outK;             // 0x2070
    V3_104d00 out2;                // 0x2074
    void FUN_00035550(V3_104d00 *out);
};

struct Target_104d00;

struct Sub58_104d00 {
    char pad0[8];
    Target_104d00 *tgt;            // 0x8
};

struct Target_104d00 {
    char pad0[8];
    Agent_104d00 *agent;           // 0x8
    int kind;               // 0xc
    char pad10[0x40 - 0x10];
    V3_104d00 pos40;
};

class Owner58 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Agent_104d00 *vfunc_6();
    char pad04[0x58 - 4];
    Sub58_104d00 sub58;
};

  // 4.0
  // 3.0

char __cdecl FUN_00018960(float a, float b, float eps);

void CPathGraphAgent::vfunc_4(int a, int b, int c) {
    V3_104d00 u;
    V3_104d00 d;
    V3_104d00 w;
    float k;

    if (!(*(Owner58 * *)&this->f_58))
        return;
    Agent_104d00 *ag = (*(Owner58 * *)&this->f_58)->vfunc_6();
    if (!ag)
        return;
    if (ag->mode->vfunc_9() == 4)
        return;

    k = 0.0f;
    u.x = 0.0f;
    u.y = 0.0f;
    u.z = 0.0f;
    d.x = 0.0f;
    d.y = 0.0f;
    d.z = 0.0f;
    ag->FUN_00035550(&u);
    V3_104d00 v1 = u;
    V3_104d00 v2 = u;
    (*(V3_104d00 *)&this->f_60) = ag->pos;

    Sub58_104d00 *s = &(*(Owner58 * *)&this->f_58)->sub58;
    if (s) {
        Target_104d00 *t = s->tgt;
        if (t) {
            if (t->kind == 1)
                (*(V3_104d00 *)&this->f_6c) = t->agent->pos;
            else
                (*(V3_104d00 *)&this->f_6c) = t->pos40;

            d.x = (*(V3_104d00 *)&this->f_6c).x - (*(V3_104d00 *)&this->f_60).x;
            d.y = (*(V3_104d00 *)&this->f_6c).y;
            d.z = (*(V3_104d00 *)&this->f_6c).z;
            float dy = d.y - (*(V3_104d00 *)&this->f_60).y;
            d.z = d.z - (*(V3_104d00 *)&this->f_60).z;
            float ady = dy;
            {
                union {
                    float f;
                    unsigned int u;
                } b;
                b.f = dy;
                b.u &= 0x7fffffff;
                ady = b.f;
            }
            if (ady > (*(float*)&DAT_0040d4d8)) {
                this->f_5c = 0;
            } else {
                d.y = 0.0f;
                float len = d.FUN_0022d110();
                this->f_5c = 1;
                if (this->f_5d && this->f_b4 != 2) {
                    w.x = (*(V3_104d00 *)&this->f_a4).x;
                    w.y = (*(V3_104d00 *)&this->f_a4).y;
                    w.z = (*(V3_104d00 *)&this->f_a4).z;
                    w.x = w.x - (*(V3_104d00 *)&this->f_60).x;
                    w.y = 0.0f;
                    w.z = w.z - (*(V3_104d00 *)&this->f_60).z;
                    float wl = w.FUN_0022d110();
                    if (!FUN_00018960(wl, 0.0f, 0.00001f) && len > DAT_004a1c68) {
                        v2 = w;
                        k = 1.0f;
                        v1 = w;
                    } else {
                        v2 = d;
                        k = 0.0f;
                        v1 = d;
                    }
                }
            }
        }
    }

    ag->outK = k;
    ag->out2 = v2;
    ag->out1 = v1;
}
