#include "decls/data/game/global.h"
// data: zero = DAT_003f32e0

class Obj {
  public:
    char pad[0x7d0];
    float value;
    void Set(float x);
};
void Obj::Set(float x) {
    if (x >= DAT_003f32e0)
        value = x;
}