#include "decls/data/script.h"
class type_info {
  public:
    virtual ~type_info();
};
extern int g_vftable_90840;
extern "C" unsigned char __cdecl FUN_001d04d0(const type_info&);
// Method6<Owner, void, const char*, const char*, int, int, int, int>'s initializer (name, member function): Function's
// fields (include/decls/data/script.h), then the member-function pointer; returns this.
class Owner_90840 {};
typedef void (Owner_90840::*Fn_90840)(const char*, const char*, int, int, int, int);
class Method6 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_90840 fn;
    void Init(const char*, int);
    Method6* Build(const char*, Fn_90840);
};
Method6* Method6::Build(const char* name, Fn_90840 mgr) {
    Init(name, 6);
    *(void**)this = &g_vftable_90840;
    fn = mgr;
    f.retType = FUN_001d04d0(typeid(void));
    f.argTypes[0] = FUN_001d04d0(typeid(const char*));
    f.argTypes[1] = FUN_001d04d0(typeid(const char*));
    f.argTypes[2] = FUN_001d04d0(typeid(int));
    f.argTypes[3] = FUN_001d04d0(typeid(int));
    f.argTypes[4] = FUN_001d04d0(typeid(int));
    f.argTypes[5] = FUN_001d04d0(typeid(int));
    return this;
}
