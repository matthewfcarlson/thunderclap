#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
// Closure2<CAmbientsManager, void, float, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class CAmbientsManager_7e2d0 {};
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class MethodBase_7e2d0 : public CtorV_001d0480 {
  public:
    MethodBase_7e2d0(const char* a) : CtorV_001d0480(a, 2) { }
};
template <class T, class R, class A, class B> class Method2 : public MethodBase_7e2d0 {
  public:
    typedef R (T::*Fn)(A, B);
    virtual void Invoke();
    Fn obj;
    T* fn;
    Method2(const char*, T*, Fn);
};
template <class T, class R, class A, class B> class Closure2 : public Method2<T, R, A, B> {
  public:
    virtual void Extra();
    Closure2(const char*, T*, typename Method2<T, R, A, B>::Fn);
};
template <>
Method2<CAmbientsManager_7e2d0, void, float, float>::Method2(const char* a, CAmbientsManager_7e2d0* b, Fn c)
    : MethodBase_7e2d0(a) {
    obj = c;
    retType = FUN_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e128));
    argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e128));
}
template <>
Closure2<CAmbientsManager_7e2d0, void, float, float>::Closure2(const char* a, CAmbientsManager_7e2d0* b,
                                                              Method2<CAmbientsManager_7e2d0, void, float, float>::Fn c)
    : Method2<CAmbientsManager_7e2d0, void, float, float>(a, b, c) {
    fn = b;
}
