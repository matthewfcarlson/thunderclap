#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Method6<Owner, void, const char* x4, int, int>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class Owner_be5c0 {};
typedef void (Owner_be5c0::*Fn_be5c0)(const char*, const char*, const char*, const char*, int, int);
class Function_be5c0 : public ScriptFunctionFields {
  public:
    Function_be5c0(const char*, int);
    virtual void v0();
};
class Method6_be5c0 : public Function_be5c0 {
  public:
    Method6_be5c0(const char*, Fn_be5c0);
    Fn_be5c0 m1c;
};
Method6_be5c0::Method6_be5c0(const char* p, Fn_be5c0 x) : Function_be5c0(p, 6) {
    m1c = x;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e134));
    argTypes[5] = FUN_001d04d0(((char*)&DAT_0048e134));
}
