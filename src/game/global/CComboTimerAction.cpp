// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00015330..0x00015370 (kind game, layer game, confidence medium), dominant class CComboTimerAction
#include "tree_prelude.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_fe2a0a69 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe2a0a69 {} using namespace fn_fe2a0a69;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fe2a0a69 {
struct Timer {
    float FUN_001ccc20();
    void FUN_001ccc30(float);
};
} // namespace fn_fe2a0a69
struct World {
    char pad[0x2c];
    Timer* timer;
};
namespace fn_fe2a0a69 {
class CComboTimerAction {
  public:
    unsigned char vfunc_7(float);
};


// 0x00015330 CComboTimerAction::vfunc_7 (61 B): matches/0x00015330.cpp
// sym: ?vfunc_7@CComboTimerAction@fn_fe2a0a69@@QAEEM@Z
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

} // namespace fn_fe2a0a69
