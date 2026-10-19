#include "decls/address.h"
extern "C" char hulk_at_0040048c[];
struct G {
    __int64 v;
};
extern G g_guid;
void FUN_0035e000() {
    g_guid.v = FUN_0027b020((const char*)((int)hulk_at_0040048c));
}
