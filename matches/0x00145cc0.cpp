#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* motionVtable[];
class MotionBlurAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual MotionBlurAction* vfunc_2(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int pad04[6];
    int mObject;
};
extern void DeleteThunk(MotionBlurAction*);
MotionBlurAction* MotionBlurAction::vfunc_2(int flag) {
    *(void**)this = motionVtable;
    _ReadWriteBarrier();
    if (mObject)
        mObject = 0;
    ((fight::Action *)this)->FUN_002326a0();
    if (flag & 1)
        DeleteThunk(this);
    return this;
}