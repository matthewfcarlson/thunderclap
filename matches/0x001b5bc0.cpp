#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: str1_1b5bc0 = DAT_0048e100, str2 = DAT_0048e128

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_0041da1c[];
struct This_FUN_001d0480 {
    int FUN_001d0480(const char*, int);
};
class Method3_1b5bc0 {
  public:
    hulk_intptr vtable;
    char pad04[12];
    char value10, value11, value12;
    char pad13[5];
    char value18;
    char pad19[3];
    int value1c;
    Method3_1b5bc0(int, int);
};
Method3_1b5bc0::Method3_1b5bc0(int a, int b) {
    ((This_FUN_001d0480*)this)->FUN_001d0480((const char*)a, 3);
    vtable = ((hulk_intptr)DAT_0041da1c);
    value1c = b;
    value18 = FUN_001d04d0(((char*)&DAT_0048e100));
    value10 = FUN_001d04d0(((char*)&DAT_0048e128));
    value11 = FUN_001d04d0(((char*)&DAT_0048e128));
    value12 = FUN_001d04d0(((char*)&DAT_0048e128));
}