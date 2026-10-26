#include "decls/data/engine/audio.h"
// data: g_base_364710 = DAT_004e7a78

class Base_364710 {
  public:
    void Fn();
};
class Obj_364710 : public Base_364710 {
  public:
    void Fn();
};
void Obj_364710::Fn() {
    ((Base_364710*)&(*(Base_364710*)((char*)&DAT_004e7a2c + 76)))->Fn();
}
