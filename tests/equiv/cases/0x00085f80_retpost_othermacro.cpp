// FUN_00085f80 @ 0x00085f80
// (integ8, D165; rev5) must fail: item ge(ret, 0) but macro HULK_POST_RET_GT (L2 post_macro_mismatch)
#include "compat/pre.h"
extern "C" const float DAT_003ffaa4;
struct Counter_85f80 {
    char pad[0x20];
    unsigned __int64 value;
    double FUN_00085f80();
};
// post: ge(ret, 0)
double Counter_85f80::FUN_00085f80() {
    return HULK_POST_RET_GT((double)value * DAT_003ffaa4, 0.0);
}
