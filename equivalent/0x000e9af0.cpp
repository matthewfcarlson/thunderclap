// STATUS: equivalent (tools/equiv.py level 3: 19732 inputs, branch coverage 34/34)
// HSlider::vfunc_5 @ 0x000e9af0
#include "decls/data/engine/pure3d/prop.h"

extern "C" double floor(double);
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct V3_e9af0 {
    float x, y, z;
};

namespace CDisplayEffect {
class DrawableCompositeDrawable {
public:
    virtual void v0();
    void *target;
    DrawableCompositeDrawable(void *t) : target(t) {}
};
}

class UIObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
};

class Dev_e9af0 {
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
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Wrapper_e9af0 {
    Dev_e9af0 *dev;
    void FUN_00293d00(const V3_e9af0 *v);
    void FUN_00293da0(float x, float y, float z);
};


class Metrics_e9af0 {
public:
    virtual void v0();
};

struct Font {
    char pad0[0x24];
    Metrics_e9af0 *metrics;
};

struct StrObj {
    int a;
    int b;
    int c;
};

struct LayoutEntry {
    float scale;
    int f4;
    int f8;
    int f12;
};

struct Layout_e9af0 {
    Font *font;
    int f4;
    LayoutEntry entries[8];
    int index;
    float f8c;
    Layout_e9af0 *FUN_000f7fe0(Font *font);
    void FUN_000f87f0(const StrObj *s, void *draw);
    void FUN_000f78e0();
};

class Fonts_e9af0 {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Font *v44();
};

class Obj958_e9af0 {
public:
    virtual void v0(void *x);
    int f4;
    int f8;
    char padc[8];
    float f14;
    char pad18[8];
};

struct Obj978_e9af0 {
    char pad0[0x10];
    unsigned col10;
};

struct Hold_e9af0 {
    char pad0[4];
    Fonts_e9af0 *fonts;
    char pad8[0x958 - 8];
    Obj958_e9af0 o958;
    Obj978_e9af0 o978;
};

class HSlider;

class Owner_e9af0 {
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
    virtual bool v13(HSlider *s);
    virtual void v14(V3_e9af0 *out, HSlider *s);
    virtual void v15();
    virtual float v16(HSlider *s);
    virtual float v17(HSlider *s);
    char pad04[8 - 4];
    Hold_e9af0 *hold;
};

class FEControl_e9af0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x14 - 4];
    Owner_e9af0 *owner;
    StrObj str18;
    char pad24[0x3c - 0x24];
    int f3c;
};

class HSlider : public FEControl_e9af0 {
public:
    virtual void vfunc_5();
    char pad40[0x60 - 0x40];
    UIObj *p60;
    UIObj *p64;
    char b68;
    char pad69[0x74 - 0x69];
    char b74;
    char pad75[0x78 - 0x75];
    V3_e9af0 v78;
    char pad84[0x150 - 0x84];
    float f150;
    char pad154[0x184 - 0x154];
    V3_e9af0 v184;
    UIObj *a190[0x15];
    int f1e4;
    char pad1e8[4];
    int f1ec;
    float f1f0;
};

void HSlider::vfunc_5()
{
    if (!b74)
        return;

    Layout_e9af0 layout;
    union TK {
        V3_e9af0 t;
        float k;
    } tk;

    layout.FUN_000f7fe0(owner->hold->fonts->v44());
    layout.entries[layout.index].f8 = 2;
    layout.entries[layout.index].f4 = 0;
    tk.k = owner->v17(this);
    layout.entries[layout.index].scale = owner->v16(this) * tk.k;
    layout.entries[layout.index].f12 = f3c;
    layout.f4 = f3c;
    (*(Wrapper_e9af0**)&DAT_0052c2ac)->dev->v15(0);
    if (owner->v13(this) && p60 != 0 && b68)
        p60->v8(0, 0);

    owner->v14(&tk.t, this);
    (*(Wrapper_e9af0**)&DAT_0052c2ac)->FUN_00293d00(&tk.t);
    (*(Wrapper_e9af0**)&DAT_0052c2ac)->FUN_00293d00(&v78);

    if (owner->v13(this)) {
        if (p60 != 0) {
            if (!b68)
                p60->v8(0, 0);
            layout.entries[layout.index].f12 = f1ec;
            layout.FUN_000f87f0(&str18, 0);
        } else {
            Hold_e9af0 *h1 = owner->hold;
            float a = h1->o958.f14 * 255.0f;
            layout.entries[layout.index].f12 = 0;
            Hold_e9af0 *h2 = owner->hold;
            Obj978_e9af0 *o978 = &h2->o978;
            unsigned saved = o978->col10;
            o978->col10 = (255 - (int)a) << 24;
            layout.FUN_000f87f0(&str18, &owner->hold->o978);
            o978->col10 = saved;
            layout.entries[layout.index].f12 = ((((unsigned)f3c >> 24) & 0xff) << 24) | 0xffffff;
            layout.FUN_000f87f0(&str18, &h1->o958);
        }
    } else {
        if (p64 != 0 && !b68)
            p64->v8(0, 0);
        layout.entries[layout.index].f12 = f1e4;
        layout.FUN_000f87f0(&str18, &owner->hold->o978);
    }

    (*(Wrapper_e9af0**)&DAT_0052c2ac)->dev->v16(0);
    if (a190[0] != 0) {
        (*(Wrapper_e9af0**)&DAT_0052c2ac)->dev->v15(0);
        (*(Wrapper_e9af0**)&DAT_0052c2ac)->FUN_00293d00(&v184);
        float s = f1f0;
        (*(Wrapper_e9af0**)&DAT_0052c2ac)->FUN_00293da0(s, s, s);
        a190[0]->v8(0, 0);
        int n = (int)floor((double)f150);
        int cnt = (n + 5) / 10;
        for (int i = 0; i < cnt - 1 && i < 10; i++) {
            if (a190[1 + i] != 0)
                a190[1 + i]->v8(0, 0);
        }
        if (cnt > 0) {
            if (owner->v13(this)) {
                if (a190[cnt + 10] == 0) {
                    // fall to the final device call
                } else {
                    Obj958_e9af0 *o = &owner->hold->o958;
                    CDisplayEffect::DrawableCompositeDrawable &d = *new ((void *)&tk) CDisplayEffect::DrawableCompositeDrawable(a190[cnt]);
                    int sv = o->f8;
                    o->f8 = 1;
                    o->v0(&d);
                    o->f8 = sv;
                    a190[cnt + 10]->v8(0, 0);
                }
            } else {
                if (a190[cnt] != 0)
                    a190[cnt]->v8(0, 0);
            }
        }
        (*(Wrapper_e9af0**)&DAT_0052c2ac)->dev->v16(0);
    }
    layout.FUN_000f78e0();
}
