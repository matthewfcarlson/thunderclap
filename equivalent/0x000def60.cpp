// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// COutlineDisplayEffect::vfunc_0 @ 0x000def60
struct Target {
    virtual void vfunc_0();
    virtual void vfunc_1(int v);
    virtual void vfunc_2(int *out);
    virtual float vfunc_3();
};

struct Union0;

union Slot {
    Target *obj;
    int value;
};

struct Pen {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void vfunc_15(int a);
    virtual void vfunc_16(int a);
};

struct Renderer {
    Pen *pen;
    void FUN_00293d40(float x, float y, float z);
};

extern Renderer *DAT_0052c2ac;

class COutlineDisplayEffect {
public:
    virtual void vfunc_0(Slot arg);
    int mode;
    char pad8[4];
    float scale;
    int colour;
};

void COutlineDisplayEffect::vfunc_0(Slot arg)
{
    Target *t = arg.obj;
    float f;
    float pts[8][2];
    int i;

    if (mode == 0)
        f = t->vfunc_3() * scale;
    else if (mode == 1)
        f = scale;
    else
        f = 0.0f;

    t->vfunc_2(&arg.value);
    t->vfunc_1(colour);
    DAT_0052c2ac->pen->vfunc_15(0);
    DAT_0052c2ac->FUN_00293d40(0.0f, 0.0f, 0.01f);

    float g = f * 0.70710677f;
    pts[0][0] = f;  pts[0][1] = 0.0f;
    pts[1][0] = g;  pts[1][1] = g;
    pts[2][0] = 0.0f; pts[2][1] = f;
    pts[3][0] = -g; pts[3][1] = g;
    pts[4][0] = -f; pts[4][1] = 0.0f;
    pts[5][0] = -g; pts[5][1] = -g;
    pts[6][0] = 0.0f; pts[6][1] = -f;
    pts[7][0] = g;  pts[7][1] = -g;

    for (i = 0; i < 8; i++) {
        DAT_0052c2ac->pen->vfunc_15(0);
        DAT_0052c2ac->FUN_00293d40(pts[i][0], pts[i][1], 0.0f);
        t->vfunc_0();
        DAT_0052c2ac->pen->vfunc_16(0);
    }
    DAT_0052c2ac->pen->vfunc_16(0);
    t->vfunc_1(arg.value);
}
