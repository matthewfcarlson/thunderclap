#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// data: gName = DAT_0048e128
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
// Function2's constructor (name, function): Function's fields (include/decls/data/script.h), then the bound
// function pointer.
typedef float (*Fn_86e60)(float, float);
class Function_86e60 : public ScriptFunctionFields {
  public:
    Function_86e60(const char*, int);
    virtual void f();
};
class Function2 : public Function_86e60 {
  public:
    Function2(const char*, Fn_86e60);
    virtual void f();
    Fn_86e60 value;
};
Function2::Function2(const char* a, Fn_86e60 b) : Function_86e60(a, 2) {
    value = b;
    retType = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
}
