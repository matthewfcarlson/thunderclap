// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ffb0..0x00091af0 (kind game, layer game, confidence high), dominant class CStatsManager
// (tree_prelude.h: not needed)


// 0x00090840 FUN_00090840 (128 B): matches/0x00090840.cpp [isolated: compile error C2665: 'fn_00090840::FUN_001d04d0' : none of the 2 overloads can convert parameter 1 from type 'const type_info']
// sym: ?Build@Method6@@QAEPAV1@PBDP8Owner_90840@@AEX00HHHH@Z@Z
#include "decls/data/script.h"
class type_info {
  public:
    virtual ~type_info();
};
extern int hulk_at_00400c50;
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
    void Init_001d0480(const char*, int);
    Method6* Build(const char*, Fn_90840);
};
Method6* Method6::Build(const char* name, Fn_90840 mgr) {
    Init_001d0480(name, 6);
    *(void**)this = &hulk_at_00400c50;
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

