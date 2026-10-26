#include "decls/data/game/global.h"
// data: Limit = DAT_003f32d8, Zero_1eba80 = DAT_003f32e0

class Inner_1eba80 {
  public:
    void Set(float);
};
struct Holder_1eba80 {
    Inner_1eba80* obj;
};
class C_1eba80 {
  public:
    Holder_1eba80* holder;
    char pad[0x10];
    float value;
    void F(float x);
};
void C_1eba80::F(float x) {
    if (!(x < DAT_003f32e0) && !(x > DAT_003f32d8)) {
        holder->obj->Set(x);
        value = x;
    }
}
