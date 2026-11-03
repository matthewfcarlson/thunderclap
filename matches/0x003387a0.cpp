#include "gen/owners.h"
bool owners::Obj_3387a0::FUN_003387a0(char c) {
    char* p = str;
    while (*p) {
        if (*p == c)
            return true;
        ++p;
    }
    return false;
}