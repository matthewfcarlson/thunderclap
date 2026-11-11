// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e8490..0x000e8600 (kind game, layer game, confidence high), dominant class CDisplayEffect::DrawableCompositeDrawable
#include "tree_prelude.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f008d4c1 {
#define TREE_TU_END }
namespace fn_f008d4c1 {} using namespace fn_f008d4c1;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f008d4c1 {
class Drawable_e8580 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
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

} // namespace fn_f008d4c1

// 0x000e8490 FUN_000e8490 (13 B): matches/0x000e8490.cpp
// sym: ?FUN_000e8490@T_e8490@owners@@QAEXE@Z
void owners::T_e8490::FUN_000e8490(unsigned char x) {
    mX = x;
}


// 0x000e8580 CDisplayEffect::DrawableCompositeDrawable::vfunc_0 (13 B): matches/0x000e8580.cpp
// sym: ?vfunc_0@DrawableCompositeDrawable@CDisplayEffect@@UAEXXZ
void CDisplayEffect::DrawableCompositeDrawable::vfunc_0() {
    (*(Drawable_e8580 * *)&this->f_04)->f8(0, 0);
}


// 0x000e8590 CDisplayEffect::DrawableCompositeDrawable::vfunc_1 (3 B): matches/0x000e8590.cpp
// sym: ?vfunc_1@DrawableCompositeDrawable@CDisplayEffect@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CDisplayEffect::DrawableCompositeDrawable::vfunc_1(int a) {
    (void)a;
}


// 0x000e85a0 CDisplayEffect::DrawableCompositeDrawable::vfunc_2 (13 B): matches/0x000e85a0.cpp
// sym: ?vfunc_2@DrawableCompositeDrawable@CDisplayEffect@@UAEXPAX@Z
// Same code shape as 0x0005e010 (propagated; names are from that function)
void CDisplayEffect::DrawableCompositeDrawable::vfunc_2(void* __p0) { int * p = (int *)__p0;

    *p = -1;
}


// 0x000e85b0 CDisplayEffect::DrawableCompositeDrawable::vfunc_3 (45 B): matches/0x000e85b0.cpp
// sym: ?vfunc_3@DrawableCompositeDrawable@CDisplayEffect@@UAEMXZ
hulk_freg CDisplayEffect::DrawableCompositeDrawable::vfunc_3() {
    V4_e85b0 v = *reinterpret_cast<V4_e85b0*>(*reinterpret_cast<char**>(reinterpret_cast<char*>(this) + 4) + 0x2c);
    return v.w + v.w;
}

