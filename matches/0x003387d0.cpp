#include "gen/owners.h"
unsigned char owners::Obj_3387d0::FUN_003387d0(char c) {
    char* p = s;
    while (*p != 0) {
        if (*p == c)
            return 1;
        ++p;
    }
    return 0;
}