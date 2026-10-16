// Same code shape as 0x0012fa00 (propagated; names are from that function)
#include "gen/hulkfight.h"

typedef unsigned int u32_12fa50;
class Result_12fa50 {
  public:
    void run();
};
class Helper_12fa50 {
  public:
    Result_12fa50* run(u32_12fa50);
};
extern Helper_12fa50* gGlobal_12fa50;
class ActionBase_12fa50 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
};

bool hulkfight::StatEndTrialAction::vfunc_3(int __p0, int __p1) {
    if (!(*(u32_12fa50 *)&this->f_20))
        return false;
    u32_12fa50 x = *(u32_12fa50*)((*(u32_12fa50 *)&this->f_1c) + 0x10);
    Result_12fa50* q = gGlobal_12fa50->run(x);
    q->run();
    return true;
}
