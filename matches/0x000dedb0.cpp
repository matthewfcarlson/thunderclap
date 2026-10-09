class Renderer {
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
    virtual void f11(int, int);
};
class CDisplayEffect {
  public:
    class Drawable {
      public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
    };
    class DrawableText : public Drawable {
      public:
        int value;
        Renderer* renderer;
        virtual void vfunc_0();
        virtual void vfunc_1();
        virtual void vfunc_2();
        virtual void vfunc_3();
    };
};
void CDisplayEffect::DrawableText::vfunc_0() {
    renderer->f11(value, 0);
}