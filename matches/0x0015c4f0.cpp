#include "decls/data/game/global.h"
// data: kZero_15c4f0 = DAT_003f32e0

#include "compat/ptr.h"
class C_15c4f0 {
  public:
    char pad[0x28];
    float m;
    hulk_freg f(float x);
};
hulk_freg C_15c4f0::f(float x) {
    if (x <= DAT_003f32e0)
        return DAT_003f32e0;
    hulk_freg t = x;
    *(int*)&x = 1;
    if (!(t > DAT_003f32e0))
        *(int*)&x = 0;
    return (hulk_freg)*(int*)&x * m;
}
