// Same code shape as 0x002665a0 (propagated; names are from that function)
#include "compat/ptr.h"
class C_283450 {
  public:
    char pad[12];
    C_283450* field;
    void g(int, int, int, int);
    void f(hulk_intptr, hulk_intptr, hulk_intptr, int);
};
void C_283450::f(hulk_intptr a0, hulk_intptr a1, hulk_intptr a2, int a3) {
    field->g(a0, a1, a2, a3);
}