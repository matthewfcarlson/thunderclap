#include "gen/owners.h"
int owners::Obj_278010::FUN_00278010(hulk_intptr a, int b, hulk_intptr c, int d, int e, hulk_intptr f, int g, hulk_intptr h, int i) {
    switch (state) {
    case 0:
        return A(((int)a), b, ((int)c), d, e, ((int)f), g, ((int)h), i);
    case 1:
        return B(((int)a), b, ((int)c), d, e, ((int)f), g, ((int)h), i);
    default:
        return 0;
    }
}