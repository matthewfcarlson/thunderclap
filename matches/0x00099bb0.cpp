#include "decls/data/game/hulkfight.h"
// data: gConstant = DAT_003f3388

class Sub_99bb0 {
  public:
    float Fn();
};
class Obj_99bb0 {
  public:
    char pad[0xb8];
    Sub_99bb0* mSub;
    float Fn();
};
float Obj_99bb0::Fn() {
    if (mSub)
        return mSub->Fn();
    return DAT_003f3388;
}
