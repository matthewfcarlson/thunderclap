#include "compat/ptr.h"
class C_1ca000 {
  public:
    void helper(int, int, int);
    int target(int, int);
};
int C_1ca000::target(int a, int b) {
    helper(10, a, b);
    return (hulk_intptr)this;
}