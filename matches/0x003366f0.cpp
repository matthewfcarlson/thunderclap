#include "compat/ptr.h"
class D {
  public:
    int helper(int);
};
class C_3366f0 {
  public:
    char pad[4];
    D* sub;
    int second(int, int, int);
    int target(hulk_intptr, int, hulk_intptr);
};
int C_3366f0::target(hulk_intptr a, int b, hulk_intptr c) {
    return second(sub->helper(a), b, c);
}