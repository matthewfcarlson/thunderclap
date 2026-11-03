#include "gen/owners.h"
struct ThisCall_000afaf0 {
    void Refresh();
};
void owners::Thing_afb80::FUN_000afb80(char x) {
    if (value != x)
        ((ThisCall_000afaf0*)(this))->Refresh();
    value = x;
}