#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
extern "C" char DAT_003f42cc[];
extern "C" char DAT_003f45ec[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
// Closure1's initializer (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object; returns this.
class Owner_2fd70 {};
typedef void (Owner_2fd70::*Fn_2fd70)();
class Closure1_2fd70 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_2fd70 fn;
    Owner_2fd70* owner;
    Closure1_2fd70* Fn(const char* a, Owner_2fd70* b, Fn_2fd70 c);
};
Closure1_2fd70* Closure1_2fd70::Fn(const char* a, Owner_2fd70* b, Fn_2fd70 c) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(a, 1);
    v = (void*)DAT_003f42cc;
    fn = c;
    f.retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e128));
    v = (void*)DAT_003f45ec;
    owner = b;
    return this;
}
