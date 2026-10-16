#include "gen/global.h"

struct HSlider_nv_f2150 {
    void Change2();
    void Change6();
};

char HSlider::vfunc_10(int op, int value) {
    switch (op) {
    case 2:
        if (this->f_168) {
            ((HSlider_nv_f2150*)this)->Change2();
            this->f_170 = 2;
            this->f_174 = value;
            (*(int *)&this->f_178) = 0;
        }
        return 1;
    case 6:
        if (this->f_168) {
            ((HSlider_nv_f2150*)this)->Change6();
            this->f_174 = value;
            this->f_170 = 6;
            (*(int *)&this->f_178) = 0;
            return 1;
        }
        return 1;
    default:
        return 0;
    }
}
