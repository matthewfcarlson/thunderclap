#include "decls/data/engine/global.h"
// data: formatString_27a9d0 = DAT_0042c10c

int __cdecl FUN_00345804(char* dst, const char* fmt, int value);
struct This_FUN_0027a970 {
    bool FUN_0027a970(int a);
};
class Obj_27a9d0 {
  public:
    bool Target(int a, int b);
    char pad[0x10];
    int index;
    char more[0xd24];
};
bool Obj_27a9d0::Target(int a, int b) {
    if (((This_FUN_0027a970*)this)->FUN_0027a970(a)) {
        return FUN_00345804((char*)this + 0xd38 + index * 0x60, DAT_0042c10c, b) == 1;
    }
    return false;
}
