#include "decls/address.h"
struct Timer {
    float FUN_001ccc20();
    void FUN_001ccc30(float);
};
struct World {
    char pad[0x2c];
    Timer* timer;
};
class CComboTimerAction {
  public:
    unsigned char vfunc_7(float);
};
unsigned char CComboTimerAction::vfunc_7(float delta) {
    World* manager = DAT_004dd700;
    if (manager) {
        Timer* timer = manager->timer;
        if (timer) {
            delta += timer->FUN_001ccc20();
            timer->FUN_001ccc30(delta);
            return 1;
        }
        return 0;
    }
    return 0;
}