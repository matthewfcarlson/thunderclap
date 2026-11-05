// Same code shape as 0x00336490 (propagated; names are from that function)
#include "compat/ptr.h"
class Helper_3364c0 {
  public:
    int run(int a);
};
class Thing_3364c0 {
  public:
    int pad;
    Helper_3364c0* member;
    void consume(int x, int b);
    void combine(hulk_intptr a, hulk_intptr b);
};
void Thing_3364c0::combine(hulk_intptr a, hulk_intptr b) {
    consume(member->run(a), b);
}