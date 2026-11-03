#include "gen/global.h"
#include "gen/owners.h"
struct CCharacter_nv_42930 {
    void helper(int, float);
};
void owners::C_42930::FUN_00042930(int a, float b) {
    if (!flag && field338 == 0)
        ((CCharacter_nv_42930*)(((CCharacter*)(this))))->helper(a, b * scale);
}