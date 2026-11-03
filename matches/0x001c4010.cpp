#include "gen/owners.h"
class Engine_1c4010 {
  public:
    void Init(void*, int, int, int, int);
    int Finish(int);
};
int owners::Thing_1c4010::FUN_001c4010(hulk_intptr x) {
    if (!done) {
        (*(Engine_1c4010**)pad)->Init(pad + 0x1c, a, b, c, d);
        done = 1;
    }
    return (*(Engine_1c4010**)pad)->Finish(((int)x));
}