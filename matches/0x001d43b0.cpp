#include "decls/data/game/global.h"
// data: gName1 = DAT_0048e0e4, gName2 = DAT_0048e0f0

#include "compat/ptr.h"
#include "decls/address.h"
extern "C" char DAT_00422674[];
extern "C" char DAT_00422830[];
class ScriptHandler {};
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
class Closure1_1d43b0 : public Ctor_001d0480 {
  public:
    Closure1_1d43b0(void*, void*, void*);
};
Closure1_1d43b0::Closure1_1d43b0(void* a, void* b, void* c) : Ctor_001d0480(a, 1) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00422674);
    *(hulk_intptr*)((char*)this + 0x1c) = (hulk_intptr)c;
    *(char*)((char*)this + 0x18) = (char)FUN_001d04d0((const char*)&(*(int*)&DAT_0048e0e4));
    *(char*)((char*)this + 0x10) = (char)FUN_001d04d0((const char*)&(*(int*)&DAT_0048e0f0));
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00422830);
    *(hulk_intptr*)((char*)this + 0x20) = (hulk_intptr)b;
}