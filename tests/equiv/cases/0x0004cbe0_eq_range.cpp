struct V3 {
    float x, y, z;
};

struct Mat {
    float m[16];
    void FUN_0022c3b0(const V3 *in, V3 *out);
};

extern V3 DAT_0048fa24;

float __cdecl FUN_00224ea0(float a, float b);
float __cdecl FUN_00224fc0(float a, float b);

class Node {
public:
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
    virtual Mat *v15();
    char pad4[0x40];
    int FUN_001d64a0();
    V3 *FUN_001d6b40();
};

struct Link {
    char pad0[8];
    Node *node;
    int type;
};

struct Fighter {
    void FUN_00059a50(V3 *out);
};

struct Stats {
    char pad0[0x3a4];
    Link *link;
};

Fighter *__fastcall FUN_000592a0(void *owner);
Stats *__fastcall FUN_00059a30(Fighter *f);

struct Frame {
    float y;
    V3 w;
    V3 l;
};

class CSmartPropCSMableCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual char vfunc_7(void *owner);
    char pad4[8];
    int wantType;
};

char CSmartPropCSMableCondition::vfunc_7(void *owner)
{
    Frame f;
    Fighter *fighter = FUN_000592a0(owner);
    Link *link = FUN_00059a30(fighter)->link;
    if (!link)
        return 0;
    if (link->type != 5)
        return 0;
    Node *node = link->node;
    if (!node)
        return 0;
    int k = node->FUN_001d64a0();
    if (k != wantType)
        return 0;
    switch (k) {
    case 8:
    case 9:
        return 1;
    case 10:
    case 12:
        node->v15()->FUN_0022c3b0(&DAT_0048fa24, &f.l);
        f.y = FUN_00224ea0(f.l.x, f.l.z);
        if (k == 10)
            f.y = f.y + 1.5707964f;
        fighter->FUN_00059a50(&f.w);
        {
            V3 *p = node->FUN_001d6b40();
            f.w.x = f.w.x - p->x;
            f.w.y = f.w.y - p->y;
            f.w.z = f.w.z - p->z;
        }
        {
            float a = FUN_00224ea0(f.w.x, f.w.z);
            float d = FUN_00224fc0(f.y, a);
            union {
                float f;
                unsigned int u;
            } bits;
            bits.f = d;
            bits.u &= 0x7fffffff;
            if (!(bits.f < 0.785398f))
                return 0;
        }
        return 1;
    }
    return 0;
}
