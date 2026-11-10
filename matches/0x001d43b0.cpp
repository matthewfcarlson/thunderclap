#include "decls/data/game/global.h"
// data: gName1 = DAT_0048e0e4, gName2 = DAT_0048e0f0

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_00422674[];
extern "C" char DAT_00422830[];
// Closure1<ScriptHandler, bool, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class ScriptHandler {};
typedef bool (ScriptHandler::*Fn_1d43b0)(const char*);
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Closure1_1d43b0 : public FUN_001d0480 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_1d43b0 fn;
    ScriptHandler* owner;
    Closure1_1d43b0(const char*, ScriptHandler*, Fn_1d43b0);
};
Closure1_1d43b0::Closure1_1d43b0(const char* a, ScriptHandler* b, Fn_1d43b0 c) : FUN_001d0480(a, 1) {
    vftable = (void*)DAT_00422674;
    fn = c;
    f.retType = (char)FUN_001d04d0((const char*)&(*(int*)&DAT_0048e0e4));
    f.argTypes[0] = (char)FUN_001d04d0((const char*)&(*(int*)&DAT_0048e0f0));
    vftable = (void*)DAT_00422830;
    owner = b;
}
