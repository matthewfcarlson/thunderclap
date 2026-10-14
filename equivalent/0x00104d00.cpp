// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 21/22, incomplete)
// CPathGraphAgent::vfunc_4 @ 0x00104d00
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

extern float DAT_0040d4d8;  // 4.0
extern float DAT_004a1c68;  // 3.0

char __cdecl FUN_00018960(float a, float b, float eps);

class CPathGraphAgent {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(int a, int b, int c);
    char pad04[0x58 - 4];
    Owner58 *owner;         // 0x58
    char flag5c;
    char flag5d;
    char pad5e[2];
    V3_104d00 from;                // 0x60
    V3_104d00 to;                  // 0x6c
    char pad78[0xa4 - 0x78];
    V3_104d00 goal;                // 0xa4
    char padb0[4];
    int state;              // 0xb4
};

void CPathGraphAgent::vfunc_4(int a, int b, int c)
{
    V3_104d00 u;
    V3_104d00 d;
    V3_104d00 w;
    float k;

    if (!owner)
        return;
    Agent_104d00 *ag = owner->vfunc_6();
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
    from = ag->pos;

    Sub58_104d00 *s = &owner->sub58;
    if (s) {
        Target_104d00 *t = s->tgt;
        if (t) {
            if (t->kind == 1)
                to = t->agent->pos;
            else
                to = t->pos40;

            d.x = to.x - from.x;
            d.y = to.y;
            d.z = to.z;
            float dy = d.y - from.y;
            d.z = d.z - from.z;
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
            if (ady > DAT_0040d4d8) {
                flag5c = 0;
            } else {
                d.y = 0.0f;
                float len = d.FUN_0022d110();
                flag5c = 1;
                if (flag5d && state != 2) {
                    w.x = goal.x;
                    w.y = goal.y;
                    w.z = goal.z;
                    w.x = w.x - from.x;
                    w.y = 0.0f;
                    w.z = w.z - from.z;
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
