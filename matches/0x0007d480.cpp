#include "decls/data/script.h"
class type_info {
  public:
    virtual ~type_info();
};
extern int g_vftable_7d480;
extern "C" unsigned char __cdecl FUN_001d04d0(const type_info&);
// Method3's initializer (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer; returns this.
class Owner_7d480 {};
typedef void (Owner_7d480::*Fn_7d480)();
class Method3 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_7d480 owner;
    void Init(const char*, int);
    Method3* Build(const char*, Fn_7d480);
};
Method3* Method3::Build(const char* name, Fn_7d480 mgr) {
    Init(name, 3);
    *(void**)this = &g_vftable_7d480;
    owner = mgr;
    f.retType = FUN_001d04d0(typeid(void));
    f.argTypes[0] = FUN_001d04d0(typeid(const char*));
    f.argTypes[1] = FUN_001d04d0(typeid(unsigned int));
    f.argTypes[2] = FUN_001d04d0(typeid(float));
    return this;
}
