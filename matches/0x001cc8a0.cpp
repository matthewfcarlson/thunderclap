#include "decls/data/game/global.h"
// data: gZero_1cc8a0 = DAT_003f32e0

#include "compat/ptr.h"
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
    if (x < DAT_003f32e0)
        x = DAT_003f32e0;
    return x;
}