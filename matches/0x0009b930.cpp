// FUN_0009b930 @ 0x0009b930
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" char DAT_00404d80[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
class Method4_9b930 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char a0, a1, a2, a3;
    char pad14[4];
    char result;
    char pad19[3];
    void* fn;
    Method4_9b930* FUN_0009b930(void*, void*);
};
Method4_9b930* Method4_9b930::FUN_0009b930(void* name, void* f) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (hulk_intptr)DAT_00404d80;
    fn = f;
    result = FUN_001d04d0(((char*)&DAT_0048e100));
    a0 = FUN_001d04d0(((char*)&DAT_0049cad8));
    a1 = FUN_001d04d0(((char*)&DAT_0049cad8));
    a2 = FUN_001d04d0(((char*)&DAT_0049cad8));
    a3 = FUN_001d04d0(((char*)&DAT_0049cad8));
    return this;
}
