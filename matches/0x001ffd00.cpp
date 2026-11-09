#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: label = DAT_0048e134
// Function (include/decls/data/script.h): the vftable, then Function's fields.
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_1ffd00 : public CtorV_001d0480 {
  public:
    Function_1ffd00(const char* a) : CtorV_001d0480(a, 0) { }
};
class Method0 : public Function_1ffd00 {
  public:
    virtual void f();
    ScriptMemberFn value;  // 0x1c
    Method0(const char* a, ScriptMemberFn c) : Function_1ffd00(a) {
        value = c;
        retType = FUN_001d04d0(((int*)&DAT_0048e134));
    }
};
class Closure0 : public Method0 {
  public:
    virtual void f();
    void* other;  // 0x20
    Closure0(const char* a, void* b, ScriptMemberFn c);
};
Closure0::Closure0(const char* a, void* b, ScriptMemberFn c) : Method0(a, c) {
    other = b;
}
