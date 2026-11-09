#include "decls/data/game/global.h"
#include "decls/data/script.h"

typedef unsigned int uint;
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
// Function (include/decls/data/script.h): the vftable, then Function's fields.
class Base : public ScriptFunctionFields {
  public:
    Base(const char*, int);
    virtual void f();
};
class Closure1_1ea440 : public Base {
  public:
    Closure1_1ea440(const char*, void*, ScriptMemberFn);
    virtual void f();
    ScriptMemberFn fn;  // 0x1c
};
class Closure1 : public Closure1_1ea440 {
  public:
    Closure1(const char*, void*, ScriptMemberFn);
    virtual void f();
    void* owner;  // 0x20
};
Closure1::Closure1(const char* s, void* p, ScriptMemberFn q) : Closure1_1ea440(s, p, q) {
    owner = p;
}
Closure1_1ea440::Closure1_1ea440(const char* s, void* p, ScriptMemberFn q) : Base(s, 1) {
    fn = q;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0049cad8));
}
