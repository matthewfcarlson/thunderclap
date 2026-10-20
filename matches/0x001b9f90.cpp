#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00420e74[];
struct Ctor_001d0480 {
    Ctor_001d0480(unsigned int, unsigned int);
};
class Method4_1b9f90 : public Ctor_001d0480 {
  public:
    Method4_1b9f90(unsigned int, unsigned int);
    hulk_intptr vptr;
    char pad04[0x0c];
    char b10, b11, b12, b13, b14, b15, b16, b17, b18;
    char pad19[3];
    int field1c;
};
Method4_1b9f90::Method4_1b9f90(unsigned int a, unsigned int b) : Ctor_001d0480(a, 4) {
    vptr = ((hulk_intptr)DAT_00420e74);
    field1c = b;
    b18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0049b95c)));
    b10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    b12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    b13 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}