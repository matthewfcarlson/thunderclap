#include "compat/ptr.h"
extern "C" char DAT_0043211c[];
class Pose {
  public:
    void* vf;
    int a, b, c;
    void Init(int);
    Pose* Make(int);
};
Pose* Pose::Make(int arg) {
    a = 0;
    b = 0;
    c = 0;
    vf = (void*)((hulk_intptr)DAT_0043211c);
    Init(arg);
    return this;
}