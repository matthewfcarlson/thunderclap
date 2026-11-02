#include "decls/data/engine/unknown.h"
// data: minimum = DAT_0042ab50

extern "C" int FUN_00262270(float x) {
    if (x < DAT_0042ab50)
        x = -100.0f;
    int n = (int)(__int64)(x * 100.0f);
    if (n > 0)
        return 0;
    if (n < -10000)
        n = -10000;
    return n;
}