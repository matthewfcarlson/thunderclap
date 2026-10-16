#include "gen/hulkfight.h"

extern int gValue_11c900;

bool hulkfight::ai::StrafeRunAction::vfunc_3(int a, int b) {
    int value = gValue_11c900;
    if (value > 8)
        value = 1;
    this->f_2c = value;
    gValue_11c900 = value + 1;
    return true;
}
