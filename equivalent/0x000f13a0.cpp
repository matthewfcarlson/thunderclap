// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FEControl::vfunc_17 @ 0x000f13a0
#include "decls/data/engine/pure3d/prop.h"

struct V3_f13a0 {
    float x, y, z;
};

void __cdecl FUN_000e09b0(V3_f13a0 a, V3_f13a0 b, unsigned int color, int mode);

class Device_f13a0 {
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

struct Holder_f13a0 {
    Device_f13a0* device;
    void FUN_00293d00(const V3_f13a0* v);
    void FUN_00293da0(float a, float b, float c);
};


class Widget_f13a0 {
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

struct Screen_f13a0 {
    char pad0[0x1818];
    Widget_f13a0* widget;
    V3_f13a0 scale;
};

struct Root_f13a0 {
    char pad0[4];
    Screen_f13a0* screen;
};

struct Parent_f13a0 {
    char pad0[8];
    Root_f13a0* root;
};

class FEControl {
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
    virtual void vfunc_17(float a1, float a2, float a3, float a4);
    virtual void v18();
    char pad04[0x10];
    Parent_f13a0* parent;
};

void FEControl::vfunc_17(float a1, float a2, float a3, float a4)
{
    Screen_f13a0* screen = parent->root->screen;
    Widget_f13a0* widget = screen->widget;
    if (widget == 0) {
        V3_f13a0 va;
        va.x = a1;
        va.y = a2;
        va.z = 0.0f;
        V3_f13a0 vb;
        vb.x = a3;
        vb.y = a4;
        vb.z = 0.0f;
        FUN_000e09b0(va, vb, 0xff4d5eff, 2);
        return;
    }
    V3_f13a0 scale = screen->scale;
    (*(Holder_f13a0**)&DAT_0052c2ac)->device->v15(0);
    V3_f13a0 center;
    if (a3 > 0.0f && a1 < 0.0f)
        center.x = (a1 + a3) * 0.5f;
    else
        center.x = (a3 - a1) * 0.5f;
    if (a2 > 0.0f && a4 < 0.0f)
        center.y = (a2 + a4) * 0.5f;
    else
        center.y = (a4 - a2) * 0.5f;
    center.z = 0.0f;
    (*(Holder_f13a0**)&DAT_0052c2ac)->FUN_00293d00(&center);
    union {
        float f;
        unsigned int u;
    } h, w;
    h.f = a2 - a4;
    w.f = a1 - a3;
    h.u &= 0x7fffffff;
    w.u &= 0x7fffffff;
    (*(Holder_f13a0**)&DAT_0052c2ac)->FUN_00293da0(w.f / scale.x, h.f / scale.y, 1.0f);
    widget->v8(0, 0);
    (*(Holder_f13a0**)&DAT_0052c2ac)->device->v16(0);
}
