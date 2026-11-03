// Same code shape as 0x001c4010 (propagated; names are from that function)
#include "gen/owners.h"
class Engine_1c4050 {
  public:
    void Init(void*, int, int, int, int);
    int Finish(int);
};
int owners::Thing_1c4050::FUN_001c4050(hulk_intptr x) {
    if (!done) {
        (*(Engine_1c4050**)pad)->Init(pad + 0x1c, a, b, c, d);
        done = 1;
    }
    return (*(Engine_1c4050**)pad)->Finish(((int)x));
}