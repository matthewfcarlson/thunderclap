// Same code shape as 0x0027a9d0 (propagated; names are from that function)
#include "decls/data/engine/global.h"
// data: formatString_27aa20 = DAT_0042c110
#include "gen/owners.h"

int __cdecl FUN_00345804(char* dst, const char* fmt, int value);
struct This_FUN_0027a970 {
    bool FUN_0027a970(int a);
};
bool owners::Obj_27aa20::FUN_0027aa20(hulk_intptr a, hulk_intptr b) {
    if (((This_FUN_0027a970*)this)->FUN_0027a970(((int)a))) {
        return FUN_00345804((char*)this + 0xd38 + index * 0x60, DAT_0042c110, ((int)b)) == 1;
    }
    return false;
}
