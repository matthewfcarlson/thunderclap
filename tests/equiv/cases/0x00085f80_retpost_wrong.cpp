// FUN_00085f80 @ 0x00085f80
// (integ8, D165; rev5) must fail: le(ret, 1000): the original returns up to 1.8e13 (post_refuted on its own returns)
#include "compat/pre.h"
extern "C" const float DAT_003ffaa4;
struct Counter_85f80 {
    char pad[0x20];
    unsigned __int64 value;
    double FUN_00085f80();
};
// post: le(ret, 1000)
double Counter_85f80::FUN_00085f80() {
    return HULK_POST_RET_LE((double)value * DAT_003ffaa4, 1000.0);
}
