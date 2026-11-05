// Same code shape as 0x002665a0 (propagated; names are from that function)
#include "compat/ptr.h"
class C_27ffc0 {
  public:
    char pad[12];
    C_27ffc0* field;
    int g(int, int);
    int f(int, hulk_intptr);
};
int C_27ffc0::f(int a0, hulk_intptr a1) {
    return field->g(a0, a1);
}