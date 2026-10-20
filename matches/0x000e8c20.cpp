#include "gen/global.h"

class FEThing_e8c20 {
  public:
    int x;
    void* m;
};
class Target_e8c20 {
  public:
    void go();
};
class FEDoAction_e8c20 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};

void FEDoPopDialog::vfunc_1() {
    ((Target_e8c20*)(*(FEThing_e8c20 * *)&this->f_10)->m)->go();
}
