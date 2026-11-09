#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"

// Method3<Owner, void, const char*, int, A3>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class Owner_d5660 {};
typedef void (Owner_d5660::*Fn_d5660)(const char*, int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char __cdecl check(const char*);
extern const char s4[];
class Function_d5660 : public CtorV_001d0480 {
  public:
    Function_d5660(const char* str) : CtorV_001d0480(str, 3) { }
};
class Method3_d5660 : public Function_d5660 {
  public:
    virtual void f();
    Fn_d5660 value;
    Method3_d5660(const char*, Fn_d5660);
};
Method3_d5660::Method3_d5660(const char* str, Fn_d5660 n) : Function_d5660(str) {
    value = n;
    retType = check(((const char*)&DAT_0048e100));
    argTypes[0] = check(((const char*)&DAT_0048e0f0));
    argTypes[1] = check(((const char*)&DAT_0048e134));
    argTypes[2] = check(s4);
}
