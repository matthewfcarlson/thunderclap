#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_2002d0 : public ScriptFunctionFields {
  public:
    Function_2002d0(const char*, int);
    virtual void f0();
};
class Method1_2002d0 : public Function_2002d0 {
  public:
    ScriptMemberFn v1c;  // 0x1c
    Method1_2002d0(const char* a, ScriptMemberFn b) : Function_2002d0(a, 1) {
        v1c = b;
        retType = FUN_001d04d0(((char*)&DAT_0048e134));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    }
    virtual void f1();
};
class Closure1_2002d0 : public Method1_2002d0 {
  public:
    void* v20;  // 0x20
    Closure1_2002d0(const char* a, void* b, ScriptMemberFn c);
    virtual void f2();
};
Closure1_2002d0::Closure1_2002d0(const char* a, void* b, ScriptMemberFn c) : Method1_2002d0(a, c), v20(b) {}
