#include "compat/ptr.h"
#include "decls/data/script.h"
class type_info {
  public:
    virtual ~type_info();
};
extern int g_vftable_9b770;
// Method5<Owner, bool, float, float, float, float, bool>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class Owner_9b770 {};
typedef bool (Owner_9b770::*Fn_9b770)(float, float, float, float, bool);
struct Ctor_001d0480 {
    Ctor_001d0480(const char*, int);
};
extern unsigned char __cdecl FUN_001d04d0(const type_info&);
class Method5_9b770 : public Ctor_001d0480 {
  public:
    Method5_9b770(const char*, Fn_9b770);
    void* vftable;
    ScriptFunctionFields fields;
    Fn_9b770 n;
};
Method5_9b770::Method5_9b770(const char* x, Fn_9b770 y) : Ctor_001d0480(x, 5) {
    *(void**)this = &g_vftable_9b770;
    n = y;
    fields.retType = FUN_001d04d0(typeid(bool));
    fields.argTypes[0] = FUN_001d04d0(typeid(float));
    fields.argTypes[1] = FUN_001d04d0(typeid(float));
    fields.argTypes[2] = FUN_001d04d0(typeid(float));
    fields.argTypes[3] = FUN_001d04d0(typeid(float));
    fields.argTypes[4] = FUN_001d04d0(typeid(bool));
}
