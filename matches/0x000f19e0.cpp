#include "gen/global.h"

struct HSlider_nv_f19e0 {
    void UpdateA(float);
    void UpdateB(float);
};
extern "C" float(__cdecl* RandomValue)();

void HSlider::vfunc_4() {
    if (this->f_154 == 1) {
        if ((*(float *)&this->f_150) < this->f_160) {
            this->f_178 = RandomValue() + this->f_178;
            float x = RandomValue();
            ((HSlider_nv_f19e0*)this)->UpdateA(x + x);
        }
    } else if (this->f_154 == 2) {
        if ((*(float *)&this->f_150) > this->f_15c) {
            this->f_178 = RandomValue() + this->f_178;
            float x = RandomValue();
            ((HSlider_nv_f19e0*)this)->UpdateB(x + x);
        }
    }
}
