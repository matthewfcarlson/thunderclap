#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" double sqrt(double);
void owners::Vec4_22b120::FUN_0022b120() {
    hulk_freg scale = 1.0f / (hulk_freg)sqrt(x * x + y * y + z * z + w * w);  // the listing's order (MSVC 7.1 reassociates; clang does not)
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
}