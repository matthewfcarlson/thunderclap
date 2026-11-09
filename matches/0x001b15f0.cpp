#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Method2's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.

typedef unsigned char u8;
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
u8 __cdecl query(const char*);
class Function_1b15f0 : public CtorV_001d0480 {
  public:
    Function_1b15f0(const char* n) : CtorV_001d0480(n, 2) { }
};
class Function2 : public Function_1b15f0 {
  public:
    virtual void f();
    ScriptMemberFn data;
    Function2(const char*, ScriptMemberFn);
};
Function2::Function2(const char* n, ScriptMemberFn d) : Function_1b15f0(n) {
    data = d;
    retType = query(((const char*)&DAT_0048e100));
    argTypes[0] = query(((const char*)&DAT_0048e128));
    argTypes[1] = query(((const char*)&DAT_0048e128));
}
