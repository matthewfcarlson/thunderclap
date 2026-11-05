#include "compat/ptr.h"
class B_1c3c10 {
  public:
    void Method(int, int);
};

class A_1c3c10 {
  public:
    B_1c3c10* m;
    void Fn(int, hulk_intptr);
};

void A_1c3c10::Fn(int a0, hulk_intptr a1) {
    m->Method(a0, a1);
}
