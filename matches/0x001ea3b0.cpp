#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: keyA = DAT_0048e100, keyB = DAT_0048e0f0

extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Function_1ea3b0 : public ScriptFunctionFields {
  public:
    virtual void Invoke(const char*);
    Function_1ea3b0(const char*, int);
    ScriptMemberFn fn;  // 0x1c
};
class Method1 : public Function_1ea3b0 {
  public:
    virtual void Invoke(const char*);
    Method1(const char* s, ScriptMemberFn p) : Function_1ea3b0(s, 1) {
        fn = p;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(const char*);
    void* owner;  // 0x20
    Closure1(const char*, void*, ScriptMemberFn);
};
Closure1::Closure1(const char* s, void* x, ScriptMemberFn p) : Method1(s, p) {
    owner = x;
}
