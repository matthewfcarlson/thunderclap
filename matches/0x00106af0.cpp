#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Method3's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern const char DAT_0048e10c[];
class Function_106af0 : public CtorV_001d0480 {
  public:
    Function_106af0(const char* name) : CtorV_001d0480(name, 3) { }
};
class Method3 : public Function_106af0 {
  public:
    virtual void f();
    ScriptMemberFn value;
    Method3(const char*, ScriptMemberFn);
};
Method3::Method3(const char* name, ScriptMemberFn v) : Function_106af0(name) {
    value = v;
    retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e134));
    argTypes[2] = FUN_001d04d0(DAT_0048e10c);
}
