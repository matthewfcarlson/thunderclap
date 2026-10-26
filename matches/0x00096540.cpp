#include "decls/data/game/unknown.h"
// data: radToDeg = DAT_003f3ef4

#include "compat/ptr.h"
extern "C" float angle(float, float);
hulk_freg FUN_00096540(float a, float b) {
    return angle(a, b) * DAT_003f3ef4;
}