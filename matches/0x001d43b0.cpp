#include "decls/address.h"
extern "C" char DAT_00422674[];
extern "C" char DAT_00422830[];
class ScriptHandler {};
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
extern int gName1;
extern int gName2;
class Closure_1d43b0 : public Ctor_001d0480 {
  public:
    Closure_1d43b0(void*, void*, void*);
};
Closure_1d43b0::Closure_1d43b0(void* a, void* b, void* c) : Ctor_001d0480(a, 1) {
    *(int*)this = ((int)DAT_00422674);
    *(int*)((char*)this + 0x1c) = (int)c;
    *(char*)((char*)this + 0x18) = (char)FUN_001d04d0((const char*)&gName1);
    *(char*)((char*)this + 0x10) = (char)FUN_001d04d0((const char*)&gName2);
    *(int*)this = ((int)DAT_00422830);
    *(int*)((char*)this + 0x20) = (int)b;
}