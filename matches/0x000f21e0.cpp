#include "gen/global.h"

struct ThisCall_000f1570 {
    void action1570();
};
struct ThisCall_000f17b0 {
    void action17b0();
};

bool HSlider::vfunc_12(int x, int y) {
    switch (x) {
    case 6:
        if (!this->f_168) {
            ((ThisCall_000f17b0*)(this))->action17b0();
            return true;
        }
        return true;
    case 2:
        if (!this->f_168)
            ((ThisCall_000f1570*)(this))->action1570();
        return true;
    default:
        return false;
    }
}
