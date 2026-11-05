#include "compat/ptr.h"
class B_3365b0 {
  public:
    int G(int);
};
class C_3365b0 {
  public:
    char pad[4];
    B_3365b0* b;
    hulk_intptr F(hulk_intptr);
    int H(int);
};
hulk_intptr C_3365b0::F(hulk_intptr param) {
    int x = b->G(param);
    return H(x);
}