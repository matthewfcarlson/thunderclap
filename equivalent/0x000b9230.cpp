// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000b9230 @ 0x000b9230
class Screen {
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
    virtual void v12(int a);
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
    virtual void v24(int mode);
    virtual int v25();
};
class Layer {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};
class Viewport {
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
    virtual float v16();
};
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
struct Canvas {
    Layer* layer;
    void FUN_00293d40(float x, float y, float z);
    void FUN_00293da0(float x, float y, float z);
};
extern Screen* DAT_0052c2a8;
extern Canvas* DAT_0052c2ac;
extern Viewport* DAT_0052c2a4;

void __cdecl FUN_000b9230(Widget* widget) {
    int saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(1);
    DAT_0052c2a8->v12(6);
    DAT_0052c2ac->layer->v15(0);
    float scale = 1.3333f / DAT_0052c2a4->v16();
    DAT_0052c2ac->layer->v13(0);
    DAT_0052c2ac->FUN_00293da0(scale, scale, 1.0f);
    DAT_0052c2ac->FUN_00293d40(-0.5f, -0.375f, 1.0f);
    if (widget)
        widget->v8(0, 0);
    DAT_0052c2ac->layer->v16(0);
    DAT_0052c2a8->v24(saved);
}
