#include "compat/ptr.h"
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f3a34[];
class Ref_1f640 {
  public:
    virtual void F();
    virtual void Release();
};
class CAction {
  public:
    CAction();
    virtual void F();
    virtual void R();
};
class CMotionTrailAction : public CAction {
  public:
    virtual void F();
    virtual void R();
    char pad08[0x18];
    Ref_1f640* m1c;
    int m20;
    int m24;
    CMotionTrailAction(int, Ref_1f640*);
};
CMotionTrailAction::CMotionTrailAction(int b, Ref_1f640* a) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f3390);
    int* q = (int*)&m1c;
    *q = 0;
    if (a)
        a->F();
    if (m1c)
        m1c->Release();
    m1c = a;
    m20 = b;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f3a34);
    m24 = 0;
}