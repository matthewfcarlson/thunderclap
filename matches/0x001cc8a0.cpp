#include "compat/ptr.h"
extern const float gZero_1cc8a0;
class C_1cc8a0 {
  public:
    char pad[0x1198];
    float a;
    float b;
};
hulk_freg __fastcall FUN_001cc8a0(C_1cc8a0* p) {
    if (*(int*)&p->b == (int)0xbf800000)
        return p->a;
    hulk_freg x = p->b - p->a;
    if (x < gZero_1cc8a0)
        x = gZero_1cc8a0;
    return x;
}