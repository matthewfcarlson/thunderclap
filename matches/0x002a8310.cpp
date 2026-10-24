#include "gen/pure3d.h"

struct CompDrawVisibilityAnimationController_nv_2a8310 {
    void Update();
};

void pure3d::CompDrawVisibilityAnimationController::FUN_002a8310(int x) {
    (*(int *)&this->f_40) = x;
    ((CompDrawVisibilityAnimationController_nv_2a8310*)this)->Update();
}
