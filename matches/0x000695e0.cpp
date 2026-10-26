#include "decls/data/game/hulkfight.h"
// data: minusOne = DAT_003f3388

class A_695e0 {
    char pad[0x18];
    float values[8];

  public:
    float f(int i);
};
float A_695e0::f(int i) {
    if (i >= 0 && i < 8)
        return values[i];
    return DAT_003f3388;
}