#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct Function_2e9a0 : public ScriptFunctionFields {
    virtual void f0();
    Function_2e9a0(const char*, int);
};
class Owner_2e9a0 {};
typedef void (Owner_2e9a0::*Fn_2e9a0)();
struct Method1 : Function_2e9a0 {
    Method1(const char* a, Fn_2e9a0 b) : Function_2e9a0(a, 1) {
        m1c = b;
        retType = FUN_001d04d0(((const char*)&DAT_0048e134));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    virtual void f0();
    Fn_2e9a0 m1c;
};
struct Closure1 : Method1 {
    Closure1(const char* a, Owner_2e9a0* c, Fn_2e9a0 b);
    virtual void f0();
    Owner_2e9a0* m20;
};
Closure1::Closure1(const char* a, Owner_2e9a0* c, Fn_2e9a0 b) : Method1(a, b) {
    m20 = c;
}
