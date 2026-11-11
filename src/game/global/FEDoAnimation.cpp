// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1760..0x000e1840 (kind game, layer game, confidence high), dominant class FEDoAnimation
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f25369eb {
#define TREE_TU_END }
namespace fn_f25369eb {} using namespace fn_f25369eb;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f25369eb {
class FEDoAction_e1760 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class Obj_e1760 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(float);
    virtual float g();
};
struct FEDoAnimation_nv_e1760 {
};
class FEDoAction_e17b0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Helper_e17b0 {
  public:
    virtual void a();
    virtual void b(FEDoAnimation*);
    virtual void c();
    virtual void d();
    virtual void e(float);
    virtual float f();
    char pad[0x54];
    int done;
};
struct FEDoAnimation_nv_e17b0 {
};
class FEDoAction_e1830 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
};
class Other_e1830 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void vfunc_3();
};

} // namespace fn_f25369eb

// 0x000e1760 FEDoAnimation::vfunc_3 (76 B): matches/0x000e1760.cpp
// sym: ?vfunc_3@FEDoAnimation@@UAEXXZ
void FEDoAnimation::vfunc_3() {
    if ((*(Obj_e1760 * *)&this->f_34)) {
        if (this->f_3c < 0.0f) {
            this->f_3c = (*(Obj_e1760 * *)&this->f_34)->g();
            ((owners::Obj_e0100 *)(((FEDoAnimation_nv_e1760*)this)))->FUN_000e0100();
            return;
        }
        if (this->f_3c > -1.0f)
            (*(Obj_e1760 * *)&this->f_34)->e(this->f_3c);
        else
            (*(Obj_e1760 * *)&this->f_34)->e(0.0f);
    }
}


// 0x000e17b0 FEDoAnimation::vfunc_1 (104 B): matches/0x000e17b0.cpp
// sym: ?vfunc_1@FEDoAnimation@@UAEXXZ
// data: minusone = DAT_003f3388, zero_e17b0 = DAT_003f32e0
void FEDoAnimation::vfunc_1() {
    Helper_e17b0* h = (*(Helper_e17b0 * *)&this->f_34);
    if (h) {
        if (this->f_40 != DAT_003f32e0) {
            this->f_3c = h->f();
            ((owners::Obj_e0100 *)(((FEDoAnimation_nv_e17b0*)this)))->FUN_000e0100();
        } else if (this->f_3c > DAT_003f3388) {
            h->e(this->f_3c);
        }
        int d = (this->f_50 == 0);
        (*(Helper_e17b0 * *)&this->f_34)->done = d;
        (*(Helper_e17b0 * *)&this->f_34)->b(this);
        this->f_38 = 2;
    }
}


// 0x000e1820 FEDoAnimation::vfunc_2 (15 B): matches/0x000e1820.cpp [wrapped: conflict: FEDoAction; FEDoAnimation]
// sym: ?vfunc_2@FEDoAnimation@fn_000e1820@@UAEXXZ
namespace fn_000e1820 {
class FEDoAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class FEDoAnimation : public FEDoAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_5();
    char pad[0x30];
    void* mTarget;
};
void FEDoAnimation::vfunc_2() {
    if (mTarget) {
        ((FEDoAction*)mTarget)->f2();
    }
}
} // namespace fn_000e1820


// 0x000e1830 FEDoAnimation::vfunc_5 (15 B): matches/0x000e1830.cpp
// sym: ?vfunc_5@FEDoAnimation@@UAEXXZ
void FEDoAnimation::vfunc_5() {
    if ((*(Other_e1830 * *)&this->f_34))
        (*(Other_e1830 * *)&this->f_34)->vfunc_3();
}

