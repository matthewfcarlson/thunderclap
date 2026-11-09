#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00404c60[];
struct Function_9aba0 {
    void Init(const char*, int);
};
// Method4<Owner, void, bool, bool, bool, float>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer.
class Owner_9aba0 {};
typedef void (Owner_9aba0::*Fn_9aba0)(bool, bool, bool, float);
class Method4_9aba0 : public Function_9aba0 {
  public:
    Method4_9aba0* Init(const char*, Fn_9aba0);
    void* vf;
    ScriptFunctionFields f;
    Fn_9aba0 member1c;
};
Method4_9aba0* Method4_9aba0::Init(const char* a, Fn_9aba0 p) {
    Function_9aba0::Init(a, 4);
    vf = (void*)DAT_00404c60;
    member1c = p;
    f.retType = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[3] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}