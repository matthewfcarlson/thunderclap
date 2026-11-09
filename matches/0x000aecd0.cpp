#include "decls/data/game/global.h"
#include "decls/data/script.h"
// data: str1_aecd0 = DAT_0048e100, str2 = DAT_0048e134, str3 = DAT_0048e0e4

extern "C" unsigned char FUN_001d04d0(const char*);
// Closure2<Owner, void, int, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_aecd0 {};
typedef void (Owner_aecd0::*Fn_aecd0)(int, bool);
class Function_aecd0 : public ScriptFunctionFields {
  public:
    Function_aecd0(const char*, int);
    virtual void f();
    Fn_aecd0 val;
    Owner_aecd0* other;
};
class Method2 : public Function_aecd0 {
  public:
    Method2(const char* p, Fn_aecd0 n) : Function_aecd0(p, 2) {
        val = n;
        retType = FUN_001d04d0(((char*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
        argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure2 : public Method2 {
  public:
    Closure2(const char* p, Owner_aecd0* m, Fn_aecd0 n);
    virtual void f();
};
Closure2::Closure2(const char* p, Owner_aecd0* m, Fn_aecd0 n) : Method2(p, n) {
    other = m;
}
