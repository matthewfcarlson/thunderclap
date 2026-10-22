#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" char DAT_003f431c[];
class Function_2e2b0 {
  public:
    Function_2e2b0(int, int);
};
class Method3_2e2b0 : public Function_2e2b0 {
  public:
    hulk_intptr v;
    char pad[0x18];
    int m1c;
    Method3_2e2b0(int, int);
};
extern char __cdecl ReadValue(const char*);
Method3_2e2b0::Method3_2e2b0(int a, int b) : Function_2e2b0(a, 3) {
    v = ((hulk_intptr)DAT_003f431c);
    m1c = b;
    *((char*)this + 0x18) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    *((char*)this + 0x10) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x11) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x12) = ReadValue((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
}