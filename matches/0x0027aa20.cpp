// Same code shape as 0x0027a9d0 (propagated; names are from that function)
#include "decls/data/engine/global.h"
// data: formatString_27aa20 = DAT_0042c110

int __cdecl FUN_00345804(char* dst, const char* fmt, int value);
struct This_FUN_0027a970 {
    bool FUN_0027a970(int a);
};
class Obj_27aa20 {
  public:
    bool Target(int a, int b);
    char pad[0x10];
    int index;
    char more[0xd24];
};
bool Obj_27aa20::Target(int a, int b) {
    if (((This_FUN_0027a970*)this)->FUN_0027a970(a)) {
        return FUN_00345804((char*)this + 0xd38 + index * 0x60, DAT_0042c110, b) == 1;
    }
    return false;
}
