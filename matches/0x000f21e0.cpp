#include "gen/global.h"

void action1570();
void action17b0();

bool HSlider::vfunc_12(int x, int y) {
    switch (x) {
    case 6:
        if (!this->f_168) {
            action17b0();
            return true;
        }
        return true;
    case 2:
        if (!this->f_168)
            action1570();
        return true;
    default:
        return false;
    }
}
