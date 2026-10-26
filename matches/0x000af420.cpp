#include "decls/data/game/global.h"
// data: fallback = DAT_00405e5c, results = DAT_004dda14, thresholds = DAT_004dda28

float __cdecl target(float x) {
    int i = 4;
    do {
        if (((float*)&DAT_004dda28)[i] <= x)
            return ((float*)&DAT_004dda14)[i];
        --i;
    } while (i >= 0);
    return DAT_00405e5c;
}
