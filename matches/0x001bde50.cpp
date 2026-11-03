#include "gen/owners.h"
bool owners::Thing_1bde50::FUN_001bde50(int x) {
    value = x;
    if (a) {
        a->Prepare(x);
        a->Finish();
    }
    if (b) {
        b->Prepare(value);
        b->Finish();
    }
    return true;
}