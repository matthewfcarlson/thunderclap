// FUN_001e0cb0 @ 0x001e0cb0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00423498[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
class MethodObj_1e0cb0 {
  public:
    int vptr;
    char pad4[12];
    char a0, a1, a2, a3;
    char pad14[4];
    char result;
    char pad19[3];
    void* fn;
    MethodObj_1e0cb0* FUN_001e0cb0(void*, void*);
};
MethodObj_1e0cb0* MethodObj_1e0cb0::FUN_001e0cb0(void* name, void* f) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (int)DAT_00423498;
    fn = f;
    result = FUN_001d04d0(((char*)&DAT_0048e0e4));
    a0 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    a1 = FUN_001d04d0(((char*)&DAT_0048e128));
    a2 = FUN_001d04d0(((char*)&DAT_0048e128));
    a3 = FUN_001d04d0(((char*)&DAT_0048e134));
    return this;
}
