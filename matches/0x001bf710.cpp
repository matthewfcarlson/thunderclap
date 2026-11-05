#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" char __cdecl ReadFlag(const char*);
class Function_1bf710 {
  public:
    Function_1bf710(int, int);
    virtual void Fn();
    char pad[0xc];
    char f10, f11, f12;
    char pad2[5];
    char f18;
    char pad3[3];
    int field;
};
class Method3 : public Function_1bf710 {
  public:
    Method3(hulk_intptr, hulk_intptr);
    virtual void Fn();
};
Method3::Method3(hulk_intptr a, hulk_intptr b) : Function_1bf710(a, 3) {
    field = b;
    f18 = ReadFlag(((char*)&DAT_0048e100));
    f10 = ReadFlag(((char*)&DAT_0048e128));
    f11 = ReadFlag(((char*)&DAT_0048e128));
    f12 = ReadFlag(((char*)&DAT_0048e128));
}
