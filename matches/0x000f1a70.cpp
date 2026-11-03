#include "gen/owners.h"
void owners::Obj_f1a70::FUN_000f1a70(float x) {
    if (x >= low && x <= high) {
        value = x;
        update();
    }
}