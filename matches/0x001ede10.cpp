#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_004243b8[];
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
class Obj_1ede10 : public Ctor_001d0480 {
  public:
    Obj_1ede10(const char*, int);
    int* vptr;
    char p4[0x0c];
    unsigned char m10, m11, m12, m13, m14, m15, m16, m17, m18, m19, m1a, m1b;
    int m1c;
};
Obj_1ede10::Obj_1ede10(const char* a, int b) : Ctor_001d0480(a, 4) {
    vptr = (int*)((hulk_intptr)DAT_004243b8);
    m1c = b;
    m18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    m10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    m13 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
}