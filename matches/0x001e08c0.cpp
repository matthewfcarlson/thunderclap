#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00423438[];
class Method4_1e08c0 {
  public:
    int vtable;
    char pad4[0xc];
    unsigned char a10, a11, a12, a13;
    char pad14[4];
    unsigned char a18;
    char pad19[3];
    int field1c;
    Method4_1e08c0* Init(void*, int);
};
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
Method4_1e08c0* Method4_1e08c0::Init(void* p, int b) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(p, 4);
    vtable = ((hulk_intptr)DAT_00423438);
    field1c = b;
    a18 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    a10 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    a11 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    a12 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    a13 = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}