#include "compat/ptr.h"
extern "C" unsigned int __cdecl tick();
struct Timer {
    float scale;
    unsigned int last;
    hulk_freg Delta();
};
hulk_freg Timer::Delta() {
    unsigned int t = tick();
    unsigned int d = t - last;
    hulk_freg result = (hulk_freg)d * scale;
    last = t;
    return result;
}