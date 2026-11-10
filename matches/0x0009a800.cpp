#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
extern "C" char DAT_00404c10[];
extern "C" char DAT_0048e10c[];
// Method4<Owner, void, float, float, ?, float>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class Owner_9a800 {};
typedef void (Owner_9a800::*Fn_9a800)(float, float, int, float);
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Method4_9a800 : public FUN_001d0480 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_9a800 value1c;
    Method4_9a800(const char* a, Fn_9a800 b);
};
Method4_9a800::Method4_9a800(const char* a, Fn_9a800 b) : FUN_001d0480(a, 4) {
    *(void**)this = (void*)DAT_00404c10;
    value1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}
