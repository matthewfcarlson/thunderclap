#include "compat/ptr.h"
extern "C" char DAT_00417df0[];
class Ref_17b110 {
  public:
    virtual void f0();
    virtual void f1();
};
class Helper_17b110 {
  public:
    void cleanup();
};
class JointTrackerAction;
void delthis(JointTrackerAction*);
class JointTrackerAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual JointTrackerAction* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    char pad[0x18];
    int m1c;
    Ref_17b110* m20;
    Ref_17b110* m24;
    char pad28[0x4c];
    Ref_17b110* m74;
};
JointTrackerAction* JointTrackerAction::vfunc_2(int flag) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_00417df0);
    Ref_17b110* volatile* p = &m74;
    Ref_17b110* a = *p;
    if (a) {
        a->f1();
        m74 = 0;
    }
    if (m24) {
        m24->f1();
        m24 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((Helper_17b110*)this)->cleanup();
    if (flag & 1)
        delthis(this);
    return this;
}
