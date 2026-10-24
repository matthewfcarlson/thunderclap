#include "gen/global.h"

struct V4_e85b0 {
    float x, y, z, w;
};
class CDisplayEffect_e85b0 {
  public:
    class Drawable_e85b0 {
      public:
        virtual void a();
        virtual void b();
        virtual void c();
        virtual float vfunc_3();
    };
    };

hulk_freg CDisplayEffect::DrawableCompositeDrawable::vfunc_3() {
    V4_e85b0 v = *reinterpret_cast<V4_e85b0*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 4) + 0x2c);
    return v.w + v.w;
}
