// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e9800..0x000e9e60 (kind game, layer game, confidence high), dominant class HSlider
#include "tree_prelude.h"
#include "decls/data/engine/pure3d/prop.h"
#define TREE_TU_BEGIN namespace fn_f686bfea {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f686bfea {} using namespace fn_f686bfea;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f686bfea {
struct Source_e9800 { bool FUN_000f94f0(unsigned int, unsigned int, float*); };
struct Receiver_e9800 { void FUN_000f8b00(float); };
} // namespace fn_f686bfea
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f686bfea {
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
    char _m_pad_40[0x20];
    UIObj *p60;
    UIObj *p64;
    char b68;
    char _m_pad_69[0xb];
    char b74;
    char _m_pad_75[0x3];
    V3_e9af0 v78;
    char _m_pad_84[0xc];
    unsigned int key0;
    unsigned int key1;
    char _m_pad_98[0xb8];
    union { float f150; float value; };
    char _m_pad_154[0x8];
    float minimum;
    float maximum;
    float fallback;
    char _m_pad_168[0x18];
    Receiver_e9800* receiver;
    V3_e9af0 v184;
    UIObj *a190[0x15];
    int f1e4;
    char _m_pad_1e8[0x4];
    int f1ec;
    float f1f0;
    void vfunc_7(Source_e9800* source);
};


// 0x000e9800 HSlider::vfunc_7 (194 B): equivalent/0x000e9800.cpp
// sym: ?vfunc_7@HSlider@fn_f686bfea@@QAEXPAUSource_e9800@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// HSlider::vfunc_7 @ 0x000e9800
void HSlider::vfunc_7(Source_e9800* source) {
 if (!(key0 | key1)) return;
 float incoming;
 float v;
 if (source->FUN_000f94f0(key0,key1,&incoming)) v=incoming; else v=fallback;
 if (v >= minimum && v <= maximum) value=v;
 else if (v > maximum) value=maximum;
 else value=minimum;
 if (receiver) receiver->FUN_000f8b00(value);
}

} // namespace fn_f686bfea

// 0x000e98d0 HSlider::vfunc_3 (544 B): equivalent/0x000e98d0.cpp [wrapped: conflict: HSlider]
// sym: ?vfunc_3@HSlider@fn_000e98d0@@UAEXXZ
namespace fn_000e98d0 {
// STATUS: equivalent (tools/equiv.py level 3: 20023 inputs, branch coverage 6/6)
// HSlider::vfunc_3 @ 0x000e98d0
class Metrics_e98d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    float FUN_000dfbf0(const char *s);
};

struct Font {
    char pad0[0x24];
    Metrics_e98d0 *metrics;
};

struct LayoutEntry {
    float scale;
    int f4;
    int f8;
    int f12;
};

struct Layout_e98d0 {
    Font *font;
    int f4;
    LayoutEntry entries[8];
    int index;
    float f8c;
    Layout_e98d0 *FUN_000f7fe0(Font *font);
    float FUN_000f88a0(const unsigned short *text);
    void FUN_000f78e0();
};

class Fonts_e98d0 {
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

struct Hold_e98d0 {
    char pad0[4];
    Fonts_e98d0 *fonts;
};

class HSlider;

class Owner_e98d0 {
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
    virtual float v16(HSlider *s);
    virtual float v17(HSlider *s);
    char pad04[8 - 4];
    Hold_e98d0 *hold;
};

class FEControl_e98d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14 - 4];
    Owner_e98d0 *owner;
};

class HSlider : public FEControl_e98d0 {
public:
    virtual void vfunc_3();
    unsigned short text[0xa4];
    float f160;
    char pad164[4];
    int f168;
    char pad16c[0x17c - 0x16c];
    float f17c;
};

void HSlider::vfunc_3()
{
    struct Frame {
        float k;
        Layout_e98d0 layout;
    } fr;

    FEControl_e98d0::vfunc_3();
    f17c = 0.0f;
    fr.layout.FUN_000f7fe0(owner->hold->fonts->v44());
    fr.k = owner->v17(this);
    fr.layout.entries[fr.layout.index].scale = owner->v16(this) * fr.k;
    f17c = fr.layout.FUN_000f88a0(text) + f17c;

    LayoutEntry *entry = &fr.layout.entries[fr.layout.index];
    Metrics_e98d0 *m = fr.layout.font->metrics;
    fr.k = 14.0f / m->v7();
    f17c = m->FUN_000dfbf0(": ") * entry->scale * fr.k + f17c;

    entry = &fr.layout.entries[fr.layout.index];
    m = fr.layout.font->metrics;
    fr.k = 14.0f / m->v7();
    f17c = m->FUN_000dfbf0("0") * entry->scale * fr.k + f17c;

    int digits = (int)f160;
    if (digits > 0) {
        do {
            m = fr.layout.font->metrics;
            LayoutEntry *e = &fr.layout.entries[fr.layout.index];
            fr.k = 14.0f / m->v7();
            f17c = m->FUN_000dfbf0("0") * e->scale * fr.k + f17c;
            digits = digits / 10;
        } while (digits > 0);
    }

    if (f168 > 0) {
        m = fr.layout.font->metrics;
        entry = &fr.layout.entries[fr.layout.index];
        fr.k = 14.0f / m->v7();
        f17c = m->FUN_000dfbf0(".") * entry->scale * fr.k + f17c;

        m = fr.layout.font->metrics;
        fr.k = 14.0f / m->v7();
        f17c = f168 * (m->FUN_000dfbf0("0") * entry->scale * fr.k) + f17c;
    }
    fr.layout.FUN_000f78e0();
}
} // namespace fn_000e98d0

namespace fn_f686bfea {

// 0x000e9af0 HSlider::vfunc_5 (868 B): equivalent/0x000e9af0.cpp
// sym: ?vfunc_5@HSlider@fn_f686bfea@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 19732 inputs, branch coverage 34/34)
// HSlider::vfunc_5 @ 0x000e9af0
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
            o978->col10 = (255 - (int)(__int64)a) << 24;
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
        int n = (int)(__int64)floor((double)f150);
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

} // namespace fn_f686bfea
