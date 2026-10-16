#include "gen/core.h"

class V {
  public:
    virtual void f0();
    virtual void f1();
};
struct Obj_2737a0 {
    char pad[4];
    V sub;
    char pad2[12];
    int count;
};
class Q_2737a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
};

void core::DriveCompletionRequest::vfunc_7() {
    (*(Obj_2737a0 * *)&this->f_0c)->sub.f0();
    --(*(Obj_2737a0 * *)&this->f_0c)->count;
    (*(Obj_2737a0 * *)&this->f_0c)->sub.f1();
    (*(Q_2737a0 * *)&this->f_10)->f3(this->f_14);
}
