#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
struct MessageOverlay;
struct Function_d6290 : public ScriptFunctionFields {
    virtual void f();
    Function_d6290(const char*, int);
};
struct Method1 : Function_d6290 {
    ScriptMemberFn p;
    Method1(const char*, ScriptMemberFn);
    virtual void f();
};
struct Closure1 : Method1 {
    void* q;
    Closure1(const char*, void*, ScriptMemberFn);
    virtual void f();
};
inline Method1::Method1(const char* x, ScriptMemberFn y) : Function_d6290(x, 1) {
    p = y;
    retType = FUN_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e128));
}
Closure1::Closure1(const char* a, void* b, ScriptMemberFn c) : Method1(a, c) {
    q = b;
}
