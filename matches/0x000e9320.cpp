class V {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual class FrameController* x18(int);
};
class FrameController {
  public:
    virtual void a();
};
class TextureAnimationController : public FrameController {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void x12(int);
};
class W {
  public:
    char p[8];
    V* v;
};
class R {
  public:
    char p[0x3c];
    W* w;
};
class S {
  public:
    char p[0x44];
    R* r;
};
class TextButton {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(int);
    char p[0x40];
    int val;
    char q[8];
    S* obj;
    char pad[0xf4];
    int saved;
};
void TextButton::f14(int) {
    saved = val;
    if (obj) {
        TextureAnimationController* z = dynamic_cast<TextureAnimationController*>(obj->r->w->v->x18(0));
        if (z)
            z->x12(0);
    }
}
