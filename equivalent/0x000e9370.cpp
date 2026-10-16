// STATUS: equivalent (tools/equiv.py level 3: 962 inputs, branch coverage 24/24)
// TextButton::vfunc_5 @ 0x000e9370
#include "decls/data/engine/pure3d/prop.h"

struct Vec3_e9370 {
    float x, y, z;
};

union Word_e9370 {
    float f;
    int i;
    unsigned int u;
};

struct Cell_e9370 {
    Word_e9370 a, b, c, d;
};

struct Source;

struct Builder {
    unsigned int hdr[2];
    Cell_e9370 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source *src);
    void FUN_000f78e0();
    void FUN_000f87f0(void *a, void *b);
};

namespace pure3d {
class FrameController {
public:
    virtual void v0();
    virtual void v1();
};

class TextureAnimationController : public FrameController {
public:
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(int value);
};
}


struct Level2_e9370 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual Source *v44();
};

struct Obj958_e9370 {
    char pad0[0x14];
    float f14;
    char pad18[8];
};

struct Obj978_e9370 {
    char pad0[0x10];
    unsigned int col10;
};

struct Hold_e9370 {
    char pad0[4];
    Level2_e9370 *fonts;
    char pad8[0x958 - 8];
    Obj958_e9370 o958;
    Obj978_e9370 o978;
};

class TextButton;

class Owner_e9370 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual bool v13(TextButton *obj);
    virtual void v14(Vec3_e9370 *out, TextButton *obj);
    virtual void v15(Vec3_e9370 *out, TextButton *obj);
    virtual float v16(TextButton *obj);
    virtual float v17(TextButton *obj);
    char pad04[4];
    Hold_e9370 *hold;
};

struct Pass_e9370 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_e9370 {
    Pass_e9370 *pass;
    void FUN_00293d00(const Vec3_e9370 *v);
    void FUN_00293da0(int a, int b, int c);
};

class Widget_e9370 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

struct StrObj {
    int a;
    int b;
    int c;
};

union Quad_e9370 {
    unsigned int u;
    unsigned char b[4];
};


void __cdecl FUN_000e11a0(Vec3_e9370 v, int a, int b);
void __cdecl FUN_000e0cc0(Vec3_e9370 v, int a, int b);

class TextButton {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    char pad04[0x10];
    Owner_e9370 *owner;
    StrObj str18;
    char pad24[0x3f - 0x24];
    unsigned char alpha;
    unsigned char flag40;
    char pad41[7];
    unsigned char flag48;
    char pad49[3];
    int val4c;
    Widget_e9370 *w50;
    int v54, v58, v5c;
    Widget_e9370 *w60;
    Widget_e9370 *w64;
    char b68;
    char pad69[3];
    unsigned int v6c;
    unsigned int v70;
    unsigned char active;
    char pad75[3];
    Vec3_e9370 anchor;
    char pad84[0x141 - 0x84];
    unsigned char b141;
    char pad142[6];
    int val148;
    char pad14c[4];
    Quad_e9370 c150;
    Quad_e9370 c154;
    Quad_e9370 c158;
};

struct Frame_e9370 {
    float f1;
    Vec3_e9370 v1;
    Builder x;
};

void TextButton::vfunc_5()
{
    if (active == 0)
        return;

    Frame_e9370 f;

    if (flag40 == 1) {
        (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.v1, this);
        (*(PassHolder_e9370**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
        owner->v15(&f.v1, this);
        FUN_000e11a0(f.v1, val148, 2);
        (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (flag48 == 1) {
        (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.v1, this);
        (*(PassHolder_e9370**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
        owner->v15(&f.v1, this);
        FUN_000e0cc0(f.v1, val4c, 0);
        (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (w50 != 0) {
        (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&f.v1, this);
        (*(PassHolder_e9370**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
        (*(PassHolder_e9370**)&DAT_0052c2ac)->FUN_00293da0(v54, v58, v5c);
        w50->v8(0, 0);
        (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v16(0);
    }

    f.x.FUN_000f7fe0(owner->hold->fonts->v44());
    f.x.cells[f.x.cursor].c.u = v70;
    f.x.cells[f.x.cursor].b.u = v6c;
    f.f1 = owner->v17(this);
    f.x.cells[f.x.cursor].a.f = owner->v16(this) * f.f1;
    (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v15(0);
    if (owner->v13(this) && w60 != 0 && b68)
        w60->v8(0, 0);
    owner->v14(&f.v1, this);
    (*(PassHolder_e9370**)&DAT_0052c2ac)->FUN_00293d00(&f.v1);
    (*(PassHolder_e9370**)&DAT_0052c2ac)->FUN_00293d00(&anchor);

    if (owner->v13(this)) {
        if (w60 != 0) {
            if (!b68)
                w60->v8(0, 0);
            int a = (int)(c158.b[3] * alpha * 0.00392157f);
            f.x.cells[f.x.cursor].d.u = (a << 24) | (c158.b[2] << 16) | (c158.b[1] << 8) | c158.b[0];
            f.x.FUN_000f87f0(&str18, 0);
        } else {
            Hold_e9370 *h1 = owner->hold;
            float t = h1->o958.f14 * 255.0f;
            f.x.cells[f.x.cursor].d.u = 0;
            Hold_e9370 *h2 = owner->hold;
            Obj978_e9370 *o978 = &h2->o978;
            unsigned int saved = o978->col10;
            o978->col10 = (255 - (int)t) << 24;
            f.x.FUN_000f87f0(&str18, &owner->hold->o978);
            o978->col10 = saved;
            int a = (int)(c154.b[3] * alpha * 0.00392157f);
            f.x.cells[f.x.cursor].d.u = (a << 24) | (c154.b[2] << 16) | (c154.b[1] << 8) | c154.b[0];
            f.x.FUN_000f87f0(&str18, &h1->o958);
        }
    } else {
        if (w64 != 0)
            w64->v8(0, 0);
        f.x.cells[f.x.cursor].d.u = c150.u;
        int a = (int)(c150.b[3] * alpha * 0.00392157f);
        f.x.cells[f.x.cursor].d.u = (a << 24) | (c150.b[2] << 16) | (c150.b[1] << 8) | c150.b[0];
        if (!b141) {
            int a2 = (int)(c150.b[3] * alpha * 0.00392157f);
            f.x.cells[f.x.cursor].d.u = (a2 << 24) | 0x808080;
        }
        f.x.FUN_000f87f0(&str18, &owner->hold->o978);
    }
    (*(PassHolder_e9370**)&DAT_0052c2ac)->pass->v16(0);
    f.x.FUN_000f78e0();
}
