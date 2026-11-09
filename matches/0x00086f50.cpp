#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Function2's constructor (name, function): Function's fields (include/decls/data/script.h), then the bound
// function pointer.
typedef const char* (*Fn_86f50)(const char*, const char*);
class Function_86f50 : public ScriptFunctionFields {
  public:
    virtual void f();
    Function_86f50(const char*, int);
};
class Function2 : public Function_86f50 {
  public:
    virtual void f();
    Fn_86f50 d;
    Function2(const char*, Fn_86f50);
};
Function2::Function2(const char* s, Fn_86f50 v) : Function_86f50(s, 2) {
    d = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
