#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00425384[];
extern "C" char DAT_0048e10c[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
class Trigger_1ff360 : public Ctor_001d0480 {
  public:
    void* vft;
    char pad4[12];
    unsigned char a10, a11, a12, a13, a14;
    char pad15[3];
    unsigned char a18;
    char pad19[3];
    int m1c;
    Trigger_1ff360(const char*, int);
};
Trigger_1ff360::Trigger_1ff360(const char* s, int x) : Ctor_001d0480(s, 5) {
    vft = (void*)((hulk_intptr)DAT_00425384);
    m1c = x;
    a18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    a10 = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    a11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    a12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e134)));
    a13 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    a14 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}