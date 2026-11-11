// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
// (tree_prelude.h: not needed)


// 0x0007d480 FUN_0007d480 (89 B): matches/0x0007d480.cpp [isolated: compile error C2665: 'fn_0007d480::FUN_001d04d0' : none of the 2 overloads can convert parameter 1 from type 'const type_info']
// sym: ?Build@Method3@@QAEPAV1@PBDP8Owner_7d480@@AEXXZ@Z
#include "decls/data/script.h"
class type_info {
  public:
    virtual ~type_info();
};
extern int hulk_at_003ff024;
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
    void Init_001d0480(const char*, int);
    Method3* Build(const char*, Fn_7d480);
};
Method3* Method3::Build(const char* name, Fn_7d480 mgr) {
    Init_001d0480(name, 3);
    *(void**)this = &hulk_at_003ff024;
    owner = mgr;
    f.retType = FUN_001d04d0(typeid(void));
    f.argTypes[0] = FUN_001d04d0(typeid(const char*));
    f.argTypes[1] = FUN_001d04d0(typeid(unsigned int));
    f.argTypes[2] = FUN_001d04d0(typeid(float));
    return this;
}

