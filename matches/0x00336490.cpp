#include "compat/ptr.h"
class Helper_336490 {
  public:
    int run(int a);
};
class Thing_336490 {
  public:
    int pad;
    Helper_336490* member;
    void consume(int x, int b);
    void combine(hulk_intptr a, hulk_intptr b);
};
void Thing_336490::combine(hulk_intptr a, hulk_intptr b) {
    consume(member->run(a), b);
}