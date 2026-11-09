#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"

extern "C" char DAT_00404d00[];
class Helper_9b330 {
  public:
    void Init(const char*, int);
};
extern "C" unsigned char FUN_001d04d0(hulk_intptr);
// Method4<Owner, void, int, float, float, float>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_9b330 {};
typedef void (Owner_9b330::*Fn_9b330)(int, float, float, float);
class Method4_9b330 {
  public:
    void* vtable;
    ScriptFunctionFields f;
    Fn_9b330 m1c;
    Method4_9b330* Fn(const char*, Fn_9b330);
};
Method4_9b330* Method4_9b330::Fn(const char* a, Fn_9b330 b) {
    ((Helper_9b330*)this)->Init(a, 4);
    vtable = (void*)DAT_00404d00;
    m1c = b;
    f.retType = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}