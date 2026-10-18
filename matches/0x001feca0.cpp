// FUN_001feca0 @ 0x001feca0
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_0048e10c[];
extern "C" char DAT_004252e4[];
extern "C" void __stdcall FUN_001d0480(void*, int);
class MethodObj_1feca0 {
  public:
    int vptr;
    char pad4[12];
    char a0, a1, a2, a3;
    char pad14[4];
    char result;
    char pad19[3];
    void* fn;
    MethodObj_1feca0* FUN_001feca0(void*, void*);
};
MethodObj_1feca0* MethodObj_1feca0::FUN_001feca0(void* name, void* f) {
    FUN_001d0480(name, 4);
    vptr = (int)DAT_004252e4;
    fn = f;
    result = FUN_001d04d0(((char*)&DAT_0048e0e4));
    a0 = FUN_001d04d0(((char*)&DAT_0048e0f0));
    a1 = FUN_001d04d0(DAT_0048e10c);
    a2 = FUN_001d04d0(DAT_0048e10c);
    a3 = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}
