#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_003ffb80[];
extern "C" char DAT_0048e10c[];
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
class Target_86fc0 : public Ctor_001d0480 {
  public:
    hulk_intptr vt;
    char pad04[12];
    unsigned char b10, b11, b12, b13, b14, b15, b16, b17, b18;
    char pad19[3];
    void* member1c;
    Target_86fc0(void*, void*);
};
Target_86fc0::Target_86fc0(void* a, void* b) : Ctor_001d0480(a, 4) {
    vt = ((hulk_intptr)DAT_003ffb80);
    member1c = b;
    b18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b10 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    b11 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    b12 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    b13 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
}