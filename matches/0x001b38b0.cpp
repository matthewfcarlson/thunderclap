#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

extern "C" char DAT_0041d9a4[];
struct Ctor_001d0480 {
    Ctor_001d0480(int, int);
};
extern char __cdecl FUN_001d04d0(int);
class Target_1b38b0 : public Ctor_001d0480 {
  public:
    char pad0[0x10];
    char b10, b11, b12, b13, b14;
    char pad15[3];
    char b18;
    char pad19[3];
    int field1c;
    Target_1b38b0(int, int);
};
Target_1b38b0::Target_1b38b0(int a, int b) : Ctor_001d0480(a, 5) {
    *(volatile hulk_intptr*)this = ((hulk_intptr)DAT_0041d9a4);
    field1c = b;
    b18 = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    b11 = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    b12 = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    b13 = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    b14 = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
}