#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
extern "C" char DAT_00404d20[];
struct ThisCall_001d0480 {
    void FUN_001d0480(void*, int);
};
class Method6_9b4a0 {
  public:
    hulk_intptr vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    char b18;
    char pad19[3];
    void* p1c;
    Method6_9b4a0* Run(void*, void*);
};
Method6_9b4a0* Method6_9b4a0::Run(void* arg, void* value) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(arg, 6);
    vptr = ((hulk_intptr)DAT_00404d20);
    p1c = value;
    b18 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b10 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    b11 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    b12 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    b13 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    b14 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    b15 = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}