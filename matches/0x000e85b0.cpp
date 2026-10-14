struct V4_e85b0 {
    float x, y, z, w;
};
class CDisplayEffect {
  public:
    class Drawable {
      public:
        virtual void a();
        virtual void b();
        virtual void c();
        virtual float vfunc_3();
    };
    class DrawableCompositeDrawable : public Drawable {
      public:
        virtual void d();
        virtual void e();
        virtual void f();
        virtual float vfunc_3();
    };
};
float CDisplayEffect::DrawableCompositeDrawable::vfunc_3() {
    V4_e85b0 v = *reinterpret_cast<V4_e85b0*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 4) + 0x2c);
    return v.w + v.w;
}