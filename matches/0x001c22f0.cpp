#include "decls/data/game/Render/Canvas.h"
#include "decls/data/game/global.h"
// data: g_obj_1c22f0 = DAT_004e2318, kZero_1c22f0 = DAT_003f32e0

struct Sub_1c22f0 {
    void A(int);
    void B();
    void C();
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
    void Set(float a, float b);
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
    mSub->C();
    if ((*(Obj2_1c22f0**)&DAT_004e2318) && mF != DAT_003f32e0) {
        Set(mF, mG);
        (*(Obj2_1c22f0**)&DAT_004e2318)->v2();
    }
    mParent->Done();
}
