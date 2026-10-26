#include "compat/ptr.h"
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3d30[];
class Ref_20c40 {
  public:
    virtual void F();
    virtual void G();
};
class CAction {
  public:
    CAction();
    virtual void F();
    virtual void G();
    char pad[0x1c - 4];
    Ref_20c40* mRef;
    int mValue;
    int mOther;
};
class CSnapToWallAction : public CAction {
  public:
    CSnapToWallAction(int, Ref_20c40*);
    virtual void F();
    virtual void G();
};
CSnapToWallAction::CSnapToWallAction(int v, Ref_20c40* r) {
    int* p = (int*)this;
    *(hulk_intptr*)p = ((hulk_intptr)DAT_003f3390);
    mRef = 0;
    if (r)
        r->F();
    if (mRef)
        mRef->G();
    mRef = r;
    mValue = v;
    p[0] = ((hulk_intptr)DAT_003f3d30);
    mOther = 0;
}
