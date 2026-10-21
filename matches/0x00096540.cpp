#include "compat/ptr.h"
extern "C" float angle(float, float);
extern const float radToDeg;
hulk_freg FUN_00096540(float a, float b) {
    return angle(a, b) * radToDeg;
}