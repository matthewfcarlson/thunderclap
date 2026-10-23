// STATUS: equivalent (tools/equiv.py level 3: 19494 inputs, branch coverage 8/8)
// VScroll::vfunc_2 @ 0x000e2280
#include "decls/data/engine/pure3d/prop.h"

struct V3_e2280 {
    float x, y, z;
};

class Pen_e2280 {
public:
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

struct Renderer_e2280 {
    Pen_e2280* pen;
    void FUN_00293d00(const V3_e2280* v);
    void FUN_00293da0(V3_e2280 axis);
    void FUN_00293bf0(float angle);
};

class Child_e2280 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void vfunc_8(int a, int b);
};

class Widget_e2280 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void vfunc_5();
};

struct Item_e2280 {
    Widget_e2280* obj;
    int pad[2];
    char active;
    char pad2[3];
};

struct Anchor_e2280 {
    const V3_e2280* FUN_000f6370(V3_e2280* out);
};

void __cdecl FUN_000e11a0(V3_e2280 size, int color, int mode);

class FELayout {
public:
    virtual void a0();
    virtual void a1();
};

class VScroll : public FELayout {
public:
    virtual void vfunc_2();
    char pad04[0x14];
    Anchor_e2280 anchor;
    char pad19[0x17];
    float height;
    char pad34[0xc];
    Item_e2280 items[32];
    int itemCount;
    char pad244[0x10];
    float width;
    Child_e2280* child;
    V3_e2280 axis;
};

void VScroll::vfunc_2()
{
    V3_e2280 v;

    if (child != 0) {
        (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_15(0);
        { const V3_e2280 *anchorPos = anchor.FUN_000f6370(&v); (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293d00(anchorPos); }
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.01f;
        (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293d00(&v);
        (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293da0(axis);
        (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293bf0(-1.5707964f);
        child->vfunc_8(0, 0);
        (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_16(0);
    }

    for (int i = 0; i < itemCount; i++) {
        if (items[i].active)
            items[i].obj->vfunc_5();
    }

    (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_15(0);
    { const V3_e2280 *anchorPos = anchor.FUN_000f6370(&v); (*(Renderer_e2280**)&DAT_0052c2ac)->FUN_00293d00(anchorPos); }
    V3_e2280 size;
    size.x = width * 1.1f;
    size.y = height * 1.1f;
    size.z = 0.0f;
    FUN_000e11a0(size, -256, 2);
    (*(Renderer_e2280**)&DAT_0052c2ac)->pen->vfunc_16(0);
}
