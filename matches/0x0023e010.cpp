#include "decls/data/game/global.h"
// data: gZero = DAT_003f32e0

namespace fight {
class WaitAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char vfunc_5(int, float);
    char pad[0x20];
    float time;
};
char WaitAction::vfunc_5(int flag, float dt) {
    if (!flag) {
        time -= dt;
        return time > DAT_003f32e0 ? 1 : 0;
    }
    return 1;
}
} // namespace fight