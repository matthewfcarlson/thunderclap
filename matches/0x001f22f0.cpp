#include "decls/data/game/global.h"

class A_1f22f0 {
  public:
    void F(float, bool);
};
class B_1f22f0 {
  public:
    void G(float, bool);
};
class C_1f22f0 {
  public:
    B_1f22f0* b;
    A_1f22f0* a;
    void H(float);
    void Run(float, bool);
};
void C_1f22f0::Run(float x, bool flag) {
    a->F(x, flag);
    b->G(x, flag);
    if (flag)
        H(x);
    (*(float*)&DAT_004e3714) += x;
}