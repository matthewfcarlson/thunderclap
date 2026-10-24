#include "gen/global.h"

struct CCharacter_nv_40170 {
    bool f(int);
};

int CCharacter::FUN_00040170() {
    bool bad = false;
    for (int i = 0; i < 8; i++)
        if (!((CCharacter_nv_40170*)this)->f(i))
            bad = true;
    return !bad;
}
