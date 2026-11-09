// cl-flags: /O2 /GR /GX
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.

class CFMVManager;

class Function_1b7c00 : public ScriptFunctionFields {
  public:
    virtual ~Function_1b7c00() throw() {}
    virtual void VFunc1() throw() {}
    virtual void VFunc2() throw() {}
    Function_1b7c00(const char* a, int b); // defined externally (FUN_001d0480)
};

class Method4_1b7c00 : public Function_1b7c00 {
  public:
    ScriptMemberFn m_fn; // 0x1c

    Method4_1b7c00(const char* a1, ScriptMemberFn a2);
    virtual void Invoke(float, float, float, float) throw() {}
    virtual ~Method4_1b7c00() throw() {}
};

extern "C" unsigned char __cdecl FUN_001d04d0(void*);


Method4_1b7c00::Method4_1b7c00(const char* a1, ScriptMemberFn a2) : Function_1b7c00(a1, 4) {
    m_fn = a2;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
}
