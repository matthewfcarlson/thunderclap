#include "gen/owners.h"
void release(int);
void owners::Obj_f7a10::FUN_000f7a10(hulk_intptr value, int unused) {
    if (m10) {
        release(m10);
        m10 = 0;
        m14 = ((int)value);
        m20 = -1;
    } else {
        m14 = ((int)value);
        m20 = -1;
    }
}