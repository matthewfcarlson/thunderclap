// FUN_0009ac70 @ 0x0009ac70
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class CCameraManager {};
class Base_9ac70 : public ScriptFunctionFields {
public:
    virtual void v();
    Base_9ac70(const char*, int) throw();
};
template<class C, class R, class A1, class A2, class A3, class A4>
class Method4 : public Base_9ac70 {
public:
    R (C::*f)(A1, A2, A3, A4);
    Method4(const char* n, R (C::*x)(A1, A2, A3, A4));
    virtual void v();
};
template<> Method4<CCameraManager, void, bool, bool, bool, bool>::Method4(const char* n, void (CCameraManager::*x)(bool, bool, bool, bool)) : Base_9ac70(n, 4) {
    f = x;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(&DAT_0048e0e4);
    argTypes[1] = FUN_001d04d0(&DAT_0048e0e4);
    argTypes[2] = FUN_001d04d0(&DAT_0048e0e4);
    argTypes[3] = FUN_001d04d0(&DAT_0048e0e4);
}
