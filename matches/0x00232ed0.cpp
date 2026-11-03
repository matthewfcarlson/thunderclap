#include "gen/owners.h"
bool owners::Node_232ed0::FUN_00232ed0(owners::Node_232ed0* other) {
    owners::Node_232ed0* p = next;
    while (p) {
        if (p == other)
            return true;
        p = p->next;
    }
    return false;
}