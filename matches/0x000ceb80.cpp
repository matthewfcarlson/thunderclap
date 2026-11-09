#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/script.h"
// Method3<HUDOverlay, int, const char*, const char*, float>'s constructor (name, member function): Function's fields
// (include/decls/data/script.h), then the member-function pointer.
class HUDOverlay {};
class Function_ceb80 : public ScriptFunctionFields {
  public:
    Function_ceb80(const char*, int);
    virtual void f();
};
template <class T, class U, class V, class W, class X> class Method3 : public Function_ceb80 {
  public:
    Method3(const char*, U (T::*)(V, W, X));
    virtual void f();
    U (T::*id)(V, W, X);
};
template <>
Method3<HUDOverlay, int, const char*, const char*, float>::Method3(const char* x,
                                                                   int (HUDOverlay::*y)(const char*, const char*, float))
    : Function_ceb80(x, 3) {
    id = y;
    retType = FUN_001d04d0(((const char*)&DAT_0048e134));
    argTypes[0] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[1] = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    argTypes[2] = FUN_001d04d0(((const char*)&DAT_0048e128));
}
