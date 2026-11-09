#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1fff10 : public ScriptFunctionFields {
  public:
    Function_1fff10(const char*, int);
    virtual void Run();
    ScriptMemberFn v;  // 0x1c
    void* w;           // 0x20
};
class Method1 : public Function_1fff10 {
  public:
    Method1(const char* s, void* x, ScriptMemberFn y) : Function_1fff10(s, 1) {
        v = y;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
    }
    virtual void Run();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* s, void* x, ScriptMemberFn y);
    virtual void Run();
};
Closure1::Closure1(const char* s, void* x, ScriptMemberFn y) : Method1(s, x, y) {
    w = x;
}
