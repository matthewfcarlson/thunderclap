#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00421520[];
class Method3_1bf7c0 {
  public:
    hulk_intptr vptr;
    char pad04[0x0c];
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    hulk_intptr m1c;
    void Init(const char*, int);
    Method3_1bf7c0* Setup(const char*, const char*);
};
Method3_1bf7c0* Method3_1bf7c0::Setup(const char* a, const char* b) {
    Init(a, 3);
    vptr = ((hulk_intptr)DAT_00421520);
    m1c = (hulk_intptr)b;
    b18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    b12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}