#include "gen/owners.h"
bool Check();
void owners::Thing_87940::FUN_00087940() {
    if (!Check())
        Set(1);
    while (*state != 8) {
        StepA();
        if (*state != 8)
            StepB();
    }
    Set(1);
}