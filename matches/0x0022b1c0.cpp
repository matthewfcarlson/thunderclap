#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" double sin(double);
extern "C" double cos(double);
void owners::X_22b1c0::FUN_0022b1c0(float x) {
    a = 0;
    c = 0;
    hulk_freg h = x * 0.5f;
    b = (hulk_freg)sin(h);
    d = (hulk_freg)cos(h);
}