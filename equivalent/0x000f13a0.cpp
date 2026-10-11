// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FEControl::vfunc_17 @ 0x000f13a0
struct V3 {
    float x, y, z;
};

void __cdecl FUN_000e09b0(V3 a, V3 b, unsigned int color, int mode);

class Device {
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

struct Holder {
    Device* device;
    void FUN_00293d00(const V3* v);
    void FUN_00293da0(float a, float b, float c);
};

extern Holder* DAT_0052c2ac;

class Widget {
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

struct Screen {
    char pad0[0x1818];
    Widget* widget;
    V3 scale;
};

struct Root {
    char pad0[4];
    Screen* screen;
};

struct Parent {
    char pad0[8];
    Root* root;
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
    Parent* parent;
};

void FEControl::vfunc_17(float a1, float a2, float a3, float a4)
{
    Screen* screen = parent->root->screen;
    Widget* widget = screen->widget;
    if (widget == 0) {
        V3 va;
        va.x = a1;
        va.y = a2;
        va.z = 0.0f;
        V3 vb;
        vb.x = a3;
        vb.y = a4;
        vb.z = 0.0f;
        FUN_000e09b0(va, vb, 0xff4d5eff, 2);
        return;
    }
    V3 scale = screen->scale;
    DAT_0052c2ac->device->v15(0);
    V3 center;
    if (a3 > 0.0f && a1 < 0.0f)
        center.x = (a1 + a3) * 0.5f;
    else
        center.x = (a3 - a1) * 0.5f;
    if (a2 > 0.0f && a4 < 0.0f)
        center.y = (a2 + a4) * 0.5f;
    else
        center.y = (a4 - a2) * 0.5f;
    center.z = 0.0f;
    DAT_0052c2ac->FUN_00293d00(&center);
    union {
        float f;
        unsigned int u;
    } h, w;
    h.f = a2 - a4;
    w.f = a1 - a3;
    h.u &= 0x7fffffff;
    w.u &= 0x7fffffff;
    DAT_0052c2ac->FUN_00293da0(w.f / scale.x, h.f / scale.y, 1.0f);
    widget->v8(0, 0);
    DAT_0052c2ac->device->v16(0);
}
