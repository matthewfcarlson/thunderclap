#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" char DAT_0040a590[];
extern "C" char DAT_0048e10c[];
class Base_cf050 {
  public:
    void Init(int, int);
};
extern "C" char __cdecl GetFlag(const char*);
class Obj_cf050 : public Base_cf050 {
  public:
    int v;
    char pad[0x14];
    char m18;
    char pad2[3];
    int n;
    Obj_cf050(int, int);
};
Obj_cf050::Obj_cf050(int a, int b) {
    Init(a, 4);
    v = ((hulk_intptr)DAT_0040a590);
    n = b;
    m18 = GetFlag((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x10) = GetFlag((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x11) = GetFlag((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    *((char*)this + 0x12) = GetFlag((const char*)((hulk_intptr)DAT_0048e10c));
    *((char*)this + 0x13) = GetFlag((const char*)((hulk_intptr)DAT_0048e10c));
}