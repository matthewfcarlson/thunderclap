#include "gen/hulkfight.h"

typedef unsigned int u32_12fa00;
class Result_12fa00 {
  public:
    void run(u32_12fa00);
};
class Helper_12fa00 {
  public:
    Result_12fa00* run();
};
extern Helper_12fa00* gGlobal_12fa00;
class ActionBase_12fa00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(void*, void*);
    virtual void f4();
    virtual void f5();
};

bool hulkfight::StatBeginTrialAction::vfunc_3(int __p0, int __p1) {
    if (!(*(u32_12fa00 *)&this->f_20))
        return false;
    u32_12fa00 x = *(u32_12fa00*)((*(u32_12fa00 *)&this->f_1c) + 0x10);
    gGlobal_12fa00->run()->run(x);
    return true;
}
