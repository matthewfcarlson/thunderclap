// Same code shape as 0x00042930 (propagated; names are from that function)
#include "gen/global.h"
#include "gen/owners.h"
struct CCharacter_nv_42960 {
    void helper(int, float);
};
void owners::C_42960::FUN_00042960(int a, float b) {
    if (!flag && field338 == 0)
        ((CCharacter_nv_42960*)(((CCharacter*)(this))))->helper(a, b * scale);
}