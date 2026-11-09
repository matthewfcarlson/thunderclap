#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Method7<Owner, void, const char* x7>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class Owner_be840 {};
typedef void (Owner_be840::*Fn_be840)(const char*, const char*, const char*, const char*, const char*, const char*,
                                      const char*);
class Function_be840 : public ScriptFunctionFields {
  public:
    Function_be840(const char* a, int n);
    virtual void Call();
};

class Method7 : public Function_be840 {
  public:
    Method7(const char* a, Fn_be840 b);
    virtual void Call();
    Fn_be840 m1c;
};


Method7::Method7(const char* a, Fn_be840 b) : Function_be840(a, 7) {
    m1c = b;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[3] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[4] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[5] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[6] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
