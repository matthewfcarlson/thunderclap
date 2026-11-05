// Same code shape as 0x00336490 (propagated; names are from that function)
#include "compat/ptr.h"
class Helper_336690 {
  public:
    int run(int a);
};
class Thing_336690 {
  public:
    int pad;
    Helper_336690* member;
    void consume(int x, int b);
    void combine(hulk_intptr a, hulk_intptr b);
};
void Thing_336690::combine(hulk_intptr a, hulk_intptr b) {
    consume(member->run(a), b);
}