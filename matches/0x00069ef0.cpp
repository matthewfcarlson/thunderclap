// Same code shape as 0x0012b630 (propagated; names are from that function)
#include "compat/ptr.h"
struct Param {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};

struct CTrack_69ef0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};

struct CDrainHealthTrack_69ef0 : CTrack_69ef0, Param {
  public:
    virtual void vfunc0();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual hulk_freg GetExtent();
    virtual void vfunc10();

    int mFlags;
    float mMinX;
    float mMaxX;
    float mWidth;
    float mHeight;
};

hulk_freg CDrainHealthTrack_69ef0::GetExtent() {
    return mMaxX - mMinX;
}