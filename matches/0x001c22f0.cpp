#include "decls/data/game/Render/Canvas.h"
#include "decls/data/game/global.h"
// data: g_obj_1c22f0 = DAT_004e2318, kZero_1c22f0 = DAT_003f32e0
#include "gen/pure3d.h"
#include "gen/owners.h"

struct Sub_1c22f0 {
    void A(int);
    void B();
};
struct Obj2_1c22f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct Parent_1c22f0 {
    void Done();
};

class Thing_1c22f0 {
  public:
    void Fn();
    char pad0[4];
    Parent_1c22f0* mParent;
    char pad1[0xb4];
    Sub_1c22f0* mSub;
    int mVal;
    char pad2[12];
    float mF;
    float mG;
};

void Thing_1c22f0::Fn() {
    mSub->A(mVal);
    mSub->B();
    ((pure3d::DisplayList *)mSub)->FUN_0029bba0();
    if ((*(Obj2_1c22f0**)&DAT_004e2318) && mF != DAT_003f32e0) {
        ((owners::Obj_1c16e0 *)this)->FUN_001c16e0(mF, mG);
        (*(Obj2_1c22f0**)&DAT_004e2318)->v2();
    }
    mParent->Done();
}
