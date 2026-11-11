// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ded90..0x000dee10 (kind game, layer game, confidence high), dominant class CDisplayEffect::DrawableText
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f27df9e5 {
#define TREE_TU_END }
namespace fn_f27df9e5 {} using namespace fn_f27df9e5;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f27df9e5 {
class Renderer_dedb0 {
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
class CDisplayEffect_dedb0 {
  public:
    class Drawable_dedb0 {
      public:
        virtual void d0();
        virtual void d1();
        virtual void d2();
        virtual void d3();
    };
    };
class Inner_dedd0 {
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
    virtual void f14();
    virtual void f15();
};
class DrawableText {
  public:
    char pad[8];
    Inner_dedd0* p;
    void vfunc_1();
};

} // namespace fn_f27df9e5

// 0x000ded90 FUN_000ded90 (25 B): matches/0x000ded90.cpp [wrapped: conflict: CDisplayEffect]
// sym: ??0DrawableText@CDisplayEffect@fn_000ded90@@QAE@PAX0@Z
namespace fn_000ded90 {
class CDisplayEffect {
  public:
    class DrawableText {
      public:
        virtual void f1_000dedb0();
        virtual void f2_000dedd0();
        void* a;
        void* b;
        DrawableText(void* x, void* y);
    };
};
CDisplayEffect::DrawableText::DrawableText(void* x, void* y) {
    a = x;
    b = y;
}
} // namespace fn_000ded90


// 0x000dedb0 CDisplayEffect::DrawableText::vfunc_0 (17 B): matches/0x000dedb0.cpp
// sym: ?vfunc_0@DrawableText@CDisplayEffect@@UAEXXZ
void CDisplayEffect::DrawableText::vfunc_0() {
    (*(Renderer_dedb0 * *)&this->f_08)->f11(this->f_04, 0);
}

namespace fn_f27df9e5 {

// 0x000dedd0 CDisplayEffect::DrawableText::vfunc_1 (8 B): matches/0x000dedd0.cpp
// sym: ?vfunc_1@DrawableText@fn_f27df9e5@@QAEXXZ
void DrawableText::vfunc_1() {
    p->f15();
}

} // namespace fn_f27df9e5

// 0x000dede0 CDisplayEffect::DrawableText::vfunc_2 (20 B): matches/0x000dede0.cpp [wrapped: conflict: DrawableText]
// sym: ?f2@DrawableText@fn_000dede0@@UAEII@Z
namespace fn_000dede0 {
class Inner_dede0 {
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
    virtual void v14(unsigned int);
};
class Drawable {
  public:
    virtual void d0();
    char pad[4];
    Inner_dede0* p;
};
class DrawableText : public Drawable {
  public:
    virtual void f0();
    virtual void f1();
    virtual unsigned int f2(unsigned int);
    virtual void f3();
};
unsigned int DrawableText::f2(unsigned int x) {
    p->v14(x);
    return x;
}
} // namespace fn_000dede0


// 0x000dee00 CDisplayEffect::DrawableText::vfunc_3 (8 B): matches/0x000dee00.cpp [wrapped: conflict: CDisplayEffect]
// sym: ?v3@DrawableText@CDisplayEffect@fn_000dee00@@UAEXXZ
namespace fn_000dee00 {
class CDisplayEffect {
  public:
    class Inner {
      public:
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
    };
    class DrawableText {
      public:
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        char pad[4];
        Inner* p;
    };
};
void CDisplayEffect::DrawableText::v3() {
    p->f7();
}
} // namespace fn_000dee00

