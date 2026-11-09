#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/script.h"
// Closure1<Owner, void, const char*>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_cf840 {};
typedef void (Owner_cf840::*Fn_cf840)(const char*);
class Base : public ScriptFunctionFields {
  public:
    virtual void invoke();
    Base(const char*, int);
};
class Closure1_cf840 : public Base {
  public:
    virtual void invoke();
    Fn_cf840 object;
    Closure1_cf840(const char*, Owner_cf840*, Fn_cf840);
};
class Closure1 : public Closure1_cf840 {
  public:
    virtual void invoke();
    Owner_cf840* other;
    Closure1(const char*, Owner_cf840*, Fn_cf840);
};
Closure1::Closure1(const char* s, Owner_cf840* obj, Fn_cf840 p) : Closure1_cf840(s, obj, p) {
    other = obj;
}
Closure1_cf840::Closure1_cf840(const char* s, Owner_cf840* obj, Fn_cf840 p) : Base(s, 1) {
    object = p;
    retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
}
