// STATUS: equivalent (tools/equiv.py level 3: 711 inputs, branch coverage 129/142, incomplete)
// TextSelector::vfunc_5 @ 0x000ea7c0
// TextSelector::vfunc_5 (FUN_000ea7c0): draws a list selector - the labels, the per-entry sub
// element, the scroll arrows - through the shared glyph Builder.
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

struct Vec3_ea7c0 {
    float x, y, z;
};

union Word_ea7c0 {
    float f;
    int i;
    unsigned int u;
};

struct Cell_ea7c0 {
    Word_ea7c0 a, b, c, d;
};

struct Source;

struct Builder {
    unsigned int hdr[2];
    Cell_ea7c0 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source *src);
    void FUN_000f78e0();
    void FUN_000f87f0(void *a, void *b);
    void FUN_000f8280(unsigned int a, unsigned int b, unsigned int c);
    float FUN_000f88a0(void *a);
    void FUN_000f80e0(const char *s, void *a, void *b);
    float FUN_000e8600(const char *s, int a);
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
    virtual void v12(float value);
};
}

struct Level2_ea7c0 {
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

struct Obj958_ea7c0 {
    char pad0[0x14];
    float f14;
    char pad18[8];
};

struct Obj978_ea7c0 {
    char pad0[0x10];
    unsigned int col10;
};

struct Hold_ea7c0 {
    char pad0[4];
    Level2_ea7c0 *fonts;
    char pad8[0x958 - 8];
    Obj958_ea7c0 o958;
    Obj978_ea7c0 o978;
};

class TextSelector;

class Owner_ea7c0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual bool v13(void *obj);
    virtual void v14(Vec3_ea7c0 *out, void *obj);
    virtual void v15(Vec3_ea7c0 *out, void *obj);
    virtual float v16(void *obj);
    virtual float v17(void *obj);
    char pad04[4];
    Hold_ea7c0 *hold;
};

struct Pass_ea7c0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

struct PassHolder_ea7c0 {
    Pass_ea7c0 *pass;
    void FUN_00293d00(const Vec3_ea7c0 *v);
    void FUN_00293da0(int a, int b, int c);
    void FUN_00293d40(float x, int y, int z);
};

class Widget_ea7c0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int a, int b);
};

struct Obj8_ea7c0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17();
    virtual pure3d::FrameController *v18(int a);
};

struct Obj3c_ea7c0 {
    char pad0[8];
    Obj8_ea7c0 *p8;
};

struct Obj44 {
    char pad0[0x3c];
    Obj3c_ea7c0 *p3c;
};

class Ctl28 : public Widget_ea7c0 {
public:
    char pad04[0x44 - 4];
    Obj44 *p44;
};

struct Elem_ea7c0 {
    char data[0x24];
};

struct Str24 {
    char pad0[0x10];
    int w10;
    int i14;
    char pad18[0x24 - 0x18];
};

struct Entry_ea7c0 {
    Str24 str;
    Elem_ea7c0 *elems;
    Ctl28 *ctl;
    int count;
    int cur;
    unsigned char b34;
    char pad35[3];
};

struct ColorPack {
    unsigned int v;
    ColorPack *FUN_000115c0(int a, int b, int c, int d);
};

union Quad_ea7c0 {
    unsigned int u;
    unsigned char b[4];
};


void __cdecl FUN_000e11a0(Vec3_ea7c0 v, int a, int b);
void __cdecl FUN_000e0cc0(Vec3_ea7c0 v, int a, int b);

// The original keeps its temporaries in fixed stack words and hands pointers to them to callees;
// the checker compares what lies around those words, so the slot order is kept.
union IntFloat {
    float f;
    int i;
    unsigned int u;
};

struct Frame_ea7c0 {
    unsigned int u13c;      // E-0x13c: scratch
    union {
        ColorPack cp138;    // E-0x138: colour packer result / int temp
        int i138;
    };
    int i134;               // E-0x134: loop index
    IntFloat t130;          // E-0x130
    Vec3_ea7c0 p;                 // E-0x12c
    Obj978_ea7c0 *style;          // E-0x120
    Obj958_ea7c0 *o958;           // E-0x11c
    Vec3_ea7c0 c;                 // E-0x118
    Builder b;              // E-0x10c
    Vec3_ea7c0 vA;                // E-0x7c
    Vec3_ea7c0 vB;                // E-0x70
    ColorPack cpk;          // E-0x64
    Vec3_ea7c0 vC;                // E-0x60
    Vec3_ea7c0 vD;                // E-0x54
    Vec3_ea7c0 vE;                // E-0x48
    Vec3_ea7c0 vF;                // E-0x3c
    Vec3_ea7c0 vG;                // E-0x30
    Vec3_ea7c0 vT1;               // E-0x24
    Vec3_ea7c0 vT2;               // E-0x18
    Vec3_ea7c0 vT3;               // E-0xc
};

class TextSelector {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
    virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18();

    char pad04[0x10];
    Owner_ea7c0 *owner;                   // 0x14
    char str18[0x3c - 0x18];
    union {
        unsigned int w;
        unsigned char b[4];
    } c3c;                          // 0x3c, alpha in the top byte
    unsigned char flag40;
    char pad41[7];
    unsigned char flag48;
    char pad49[3];
    int val4c;
    Widget_ea7c0 *w50;
    int v54, v58, v5c;
    Widget_ea7c0 *w60;
    Widget_ea7c0 *w64;
    char pad68[0x74 - 0x68];
    unsigned char active;           // 0x74
    char pad75[3];
    Vec3_ea7c0 anchor;                    // 0x78
    char pad84[0xa4 - 0x84];
    void *pa4;
    char pada8[0x148 - 0xa8];
    int val148;
    char pad14c[4];
    int count;
    int index;
    Entry_ea7c0 items[128];               // 0x158
    int i1d58;
    int i1d5c;
    char pad1d60[8];
    float f1d68;
    float f1d6c;
    float f1d70;
    float f1d74;
    float f1d78;
    int i1d7c;
    int i1d80;
    char pad1d84[8];
    Widget_ea7c0 *p1d8c;
    Widget_ea7c0 *p1d90;
    char pad1d94[4];
    TextSelector *p1d98;
    Quad_ea7c0 c1d9c;
    Quad_ea7c0 c1da0;
    unsigned int i1da4;

    Vec3_ea7c0 *FUN_000e2820(Vec3_ea7c0 *out);
};

void TextSelector::vfunc_5()
{
    if (active == 0)
        return;

    Frame_ea7c0 F;
    Builder &b = F.b;

    if (flag40) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&F.c, this);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.c);
        owner->v15(&F.p, this);
        FUN_000e11a0(F.p, val148, 2);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (flag48) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&F.c, this);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.c);
        owner->v15(&F.p, this);
        FUN_000e0cc0(F.p, val4c, 0);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    }
    if (w50 != 0) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        owner->v14(&F.c, this);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.c);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293da0(v54, v58, v5c);
        w50->v8(0, 0);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    }

    b.FUN_000f7fe0(owner->hold->fonts->v44());
    F.t130.f = owner->v17(this);
    b.cells[b.cursor].a.f = owner->v16(this) * F.t130.f;
    b.cells[b.cursor].c.i = 2;
    b.cells[b.cursor].b.i = 0;
    b.cells[b.cursor].d.u = c3c.w;
    b.hdr[1] = c3c.w;
    F.o958 = &owner->hold->o958;
    if (owner->v13(this) && F.o958 == 0)
        b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008), (*(unsigned int*)&DAT_004de94c));

    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
    owner->v14(&F.c, this);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.c);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&anchor);

    F.style = 0;
    if (owner->v13(this)) {
        if (i1d5c == 0 && w60 != 0) {
            w60->v8(0, 0);
            b.cells[b.cursor].d.u = i1da4;
        } else {
            b.cells[b.cursor].d.u = c3c.w;
            F.style = &owner->hold->o978;
        }
    } else {
        if (i1d5c == 0 && w64 != 0) {
            w64->v8(0, 0);
        } else {
            F.style = &owner->hold->o978;
        }
        F.t130.i = c1d9c.b[3] * c3c.b[3];
        int a = (int)(F.t130.i * 0.00392157f);
        b.cells[b.cursor].d.u = (a << 24) | (c1d9c.b[2] << 16) | (c1d9c.b[1] << 8) | c1d9c.b[0];
    }

    if (i1d5c == 0)
        b.FUN_000f87f0(str18, F.style);
    if (p1d98 == 0) {
        float ff = b.FUN_000f88a0(str18);
        F.p.x = ff;
        F.p.y = 0.0f;
        F.p.z = 0.0f;
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.p);
        if (i1d5c == 0) {
            b.FUN_000f80e0(": ", pa4, F.style);
            float ff2 = b.FUN_000e8600(": ", 0);
            F.p.x = ff2;
            F.p.y = 0.0f;
            F.p.z = 0.0f;
            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.p);
        }
    } else {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
        p1d98->owner->v14(&F.c, p1d98);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.c);
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&anchor);
    }
    if (owner->v13(this) && F.o958 == 0)
        b.cells[b.cursor].d.u = b.hdr[1];

    if (i1d58 <= 0) {
        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
        b.FUN_000f78e0();
        return;
    }

    if (i1d5c == 0) {
        Entry_ea7c0 *cur = &items[index];
        pure3d::TextureAnimationController *tac = 0;
        if (cur->ctl)
            tac = dynamic_cast<pure3d::TextureAnimationController *>(cur->ctl->p44->p3c->p8->v18(0));
        bool foc3 = owner->v13(this);
        if (F.o958 != 0) {
            if (foc3) {
                unsigned int col;
                if (w60 != 0) {
                    col = i1da4;
                } else {
                    float t = F.o958->f14 * 255.0f;
                    b.cells[b.cursor].d.u = 0;
                    Obj978_ea7c0 *o978 = &owner->hold->o978;
                    F.u13c = o978->col10;
                    o978->col10 = (255 - (int)t) << 24;
                    b.FUN_000f87f0(&items[index], o978);
                    o978->col10 = F.u13c;
                    F.t130.i = c1da0.b[3] * c3c.b[3];
                    int a = (int)(F.t130.i * 0.00392157f);
                    col = F.cp138.FUN_000115c0(c1da0.b[2], c1da0.b[1], c1da0.b[0], a)->v;
                    b.cells[b.cursor].d.u = col;
                    b.FUN_000f87f0(&items[index], F.o958);
                    goto tac0;
                }
                b.cells[b.cursor].d.u = col;
                b.FUN_000f87f0(&items[index], F.style);
            } else {
                F.t130.i = c1d9c.b[3] * c3c.b[3];
                int a = (int)(F.t130.i * 0.00392157f);
                unsigned int col = F.cp138.FUN_000115c0(c1d9c.b[2], c1d9c.b[1], c1d9c.b[0], a)->v;
                b.cells[b.cursor].d.u = col;
                b.FUN_000f87f0(&items[index], F.style);
            }
        tac0:
            if (tac) {
                tac->v12(1.0f);
                tac->v7();
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                F.p.x = f1d74 * 0.5f;
                F.p.y = 0.0f;
                F.p.z = 0.0f;
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.p);
                items[index].ctl->v8(0, 0);
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
            }
        } else {
            if (foc3)
                b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008), (*(unsigned int*)&DAT_004de94c));
            b.FUN_000f87f0(&items[index], F.style);
            if (tac) {
                tac->v12(1.0f);
                tac->v7();
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                F.p.x = f1d74 * 0.5f;
                F.p.y = 0.0f;
                F.p.z = 0.0f;
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.p);
                items[index].ctl->v8(0, 0);
                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
            }
            if (owner->v13(this))
                b.cells[b.cursor].d.u = b.hdr[1];
        }
    } else {
        int mode = i1d5c;
        F.i134 = i1d7c;
        if (mode == 2) {
            for (; F.i134 <= i1d80; F.i134++) {
                Entry_ea7c0 *e = &items[F.i134];
                if (e->str.w10 == 0 && e->str.i14 == -1)
                    continue;
                b.cells[b.cursor].c.i = 2;
                pure3d::TextureAnimationController *tac = 0;
                if (e->ctl)
                    tac = dynamic_cast<pure3d::TextureAnimationController *>(e->ctl->p44->p3c->p8->v18(0));
                Obj958_ea7c0 *op = F.o958;
                if (op != 0) {
                    if (F.i134 == index) {
                        if (owner->v13(this)) {
                            F.t130.f = op->f14;
                            if (w60 != 0)
                                w60->v8(0, 0);
                            float t = F.t130.f * 255.0f;
                            b.cells[b.cursor].d.u = 0;
                            Hold_ea7c0 *h = owner->hold;
                            Obj978_ea7c0 *o978 = &h->o978;
                            F.u13c = o978->col10;
                            o978->col10 = (255 - (int)t) << 24;
                            b.FUN_000f87f0(&items[index], o978);
                            o978->col10 = F.u13c;
                            if (w60 != 0) {
                                b.cells[b.cursor].d.u = 0xff000000;
                            } else {
                                F.u13c = c1da0.b[3] * c3c.b[3];
                                int a = (int)((int)F.u13c * 0.00392157f);
                                b.cells[b.cursor].d.u =
                                    F.cpk.FUN_000115c0(c1da0.b[2], c1da0.b[1], c1da0.b[0], a)->v;
                            }
                            b.FUN_000f87f0(&items[index], w60 != 0 ? 0 : (void *)op);
                            if (items[index].elems) {
                                Elem_ea7c0 *el = items[index].elems + items[index].cur;
                                float *pw = &FUN_000e2820(&F.vT1)->x;
                                float wdt = b.FUN_000f88a0(el);
                                float ff = *pw - wdt;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                                F.p.x = ff;
                                F.p.y = 0.0f;
                                F.p.z = 0.0f;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.p);
                                b.FUN_000f87f0(el, w60 != 0 ? 0 : (void *)op);
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                            }
                        } else {
                            if (w64 != 0)
                                w64->v8(0, 0);
                            b.cells[b.cursor].d.u = c3c.w;
                            b.FUN_000f87f0(e, F.style);
                            if (e->elems) {
                                Elem_ea7c0 *el = e->elems + e->cur;
                                float *pw = &FUN_000e2820(&F.vT3)->x;
                                float wdt = b.FUN_000f88a0(el);
                                float ff = *pw - wdt;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                                F.vF.x = ff;
                                F.vF.y = 0.0f;
                                F.vF.z = 0.0f;
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vF);
                                b.FUN_000f87f0(el, F.style);
                                (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                            }
                        }
                    } else {
                        if (w64 != 0)
                            w64->v8(0, 0);
                        F.i138 = c1d9c.b[3] * c3c.b[3];
                        int a = (int)(F.i138 * 0.00392157f);
                        b.cells[b.cursor].d.u =
                            (a << 24) | (c1d9c.b[2] << 16) | (c1d9c.b[1] << 8) | c1d9c.b[0];
                        if (!e->b34) {
                            F.i138 = c1d9c.b[3] * c3c.b[3];
                            int a2 = (int)(F.i138 * 0.00392157f);
                            b.cells[b.cursor].d.u = (a2 << 24) | 0xc0c000;
                        }
                        b.FUN_000f87f0(e, F.style);
                        Elem_ea7c0 *ep = e->elems;
                        if (ep) {
                            Elem_ea7c0 *el = ep + e->cur;
                            float *pw = &FUN_000e2820(&F.vT2)->x;
                            float wdt = b.FUN_000f88a0(el);
                            float ff = *pw - wdt;
                            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                            F.vC.x = ff;
                            F.vC.y = 0.0f;
                            F.vC.z = 0.0f;
                            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vC);
                            b.FUN_000f87f0(el, F.style);
                            (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                        }
                    }
                    if (tac) {
                        tac->v12(0.0f);
                        tac->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        F.vG.x = f1d74 * 0.5f;
                        F.vG.y = 0.0f;
                        F.vG.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vG);
                        e->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    F.vD.x = 0.0f;
                    F.vD.y = -(f1d78 + f1d70);
                    F.vD.z = 0.0f;
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vD);
                } else {
                    if (F.i134 == index) {
                        if (owner->v13(this))
                            b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008), (*(unsigned int*)&DAT_004de94c));
                        else
                            b.cells[b.cursor].d.u = c3c.w;
                    }
                    b.FUN_000f87f0(e, 0);
                    Elem_ea7c0 *ep = e->elems;
                    if (ep) {
                        Elem_ea7c0 *el = ep + e->cur;
                        owner->v15(&F.vE, this);
                        float ff = F.vE.x - b.FUN_000f88a0(el);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        F.vA.x = ff;
                        F.vA.y = 0.0f;
                        F.vA.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vA);
                        b.FUN_000f87f0(el, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    if (tac) {
                        tac->v12(0.0f);
                        tac->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        F.vB.x = f1d74 * 0.5f;
                        F.vB.y = 0.0f;
                        F.vB.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vB);
                        e->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    F.c.x = 0.0f;
                    F.c.y = -(f1d78 + f1d70);
                    F.c.z = 0.0f;
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.c);
                    if (F.i134 == index)
                        b.cells[b.cursor].d.u = b.hdr[1];
                }
            }
        } else {
            for (; F.i134 <= i1d80; F.i134++) {
                Entry_ea7c0 *e = &items[F.i134];
                if (e->str.w10 == 0 && e->str.i14 == -1)
                    continue;
                pure3d::TextureAnimationController *tac = 0;
                if (e->ctl)
                    tac = dynamic_cast<pure3d::TextureAnimationController *>(e->ctl->p44->p3c->p8->v18(0));
                Obj958_ea7c0 *op = F.o958;
                float flag;
                if (op != 0) {
                    if (F.i134 == index) {
                        if (owner->v13(this)) {
                            float t = op->f14 * 255.0f;
                            b.cells[b.cursor].d.u = 0;
                            Obj978_ea7c0 *o978 = &owner->hold->o978;
                            F.u13c = o978->col10;
                            o978->col10 = (255 - (int)t) << 24;
                            b.FUN_000f87f0(&items[index], o978);
                            o978->col10 = F.u13c;
                            F.i138 = c1da0.b[3] * c3c.b[3];
                            int a = (int)(F.i138 * 0.00392157f);
                            b.cells[b.cursor].d.u =
                                F.cpk.FUN_000115c0(c1da0.b[2], c1da0.b[1], c1da0.b[0], a)->v;
                            b.FUN_000f87f0(&items[index], op);
                            flag = 1.0f;
                        } else {
                            b.cells[b.cursor].d.u = c3c.w;
                            b.FUN_000f87f0(e, F.style);
                            flag = 1.0f;
                        }
                    } else {
                        F.i138 = c1d9c.b[3] * c3c.b[3];
                        int a = (int)(F.i138 * 0.00392157f);
                        b.cells[b.cursor].d.u =
                            (a << 24) | (c1d9c.b[2] << 16) | (c1d9c.b[1] << 8) | c1d9c.b[0];
                        b.FUN_000f87f0(e, F.style);
                        flag = 0.0f;
                    }
                    if (tac) {
                        tac->v12(flag);
                        tac->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        F.c.x = f1d74 * 0.5f;
                        F.c.y = 0.0f;
                        F.c.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.c);
                        e->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    F.vB.x = f1d74 + f1d6c;
                    F.vB.y = 0.0f;
                    F.vB.z = 0.0f;
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vB);
                } else {
                    flag = 0.0f;
                    if (F.i134 == index) {
                        if (owner->v13(this))
                            b.FUN_000f8280((*(unsigned int*)&DAT_004a1004), (*(unsigned int*)&DAT_004a1008), (*(unsigned int*)&DAT_004de94c));
                        else
                            b.cells[b.cursor].d.u = c3c.w;
                        flag = 1.0f;
                    }
                    b.FUN_000f87f0(e, 0);
                    if (tac) {
                        tac->v12(flag);
                        tac->v7();
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
                        F.vA.x = f1d74 * 0.5f;
                        F.vA.y = 0.0f;
                        F.vA.z = 0.0f;
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vA);
                        e->ctl->v8(0, 0);
                        (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
                    }
                    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d40(f1d74 + f1d6c, 0, 0);
                    if (F.i134 == index)
                        b.cells[b.cursor].d.u = b.hdr[1];
                }
            }
        }
    }

    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    if (owner->v13(this)) {
        if (p1d8c != 0 && i1d7c != 0)
            p1d8c->v8(0, 0);
        if (p1d90 != 0 && i1d80 < i1d58 - 1)
            p1d90->v8(0, 0);
    }
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v15(0);
    owner->v14(&F.vE, this);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&F.vE);
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->FUN_00293d00(&anchor);
    if (owner->v13(this) && &owner->hold->o958 == 0)
        vfunc_18();
    (*(PassHolder_ea7c0**)&DAT_0052c2ac)->pass->v16(0);
    b.FUN_000f78e0();
}
