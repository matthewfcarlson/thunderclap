#include "compat/ptr.h"
class Ref_299170 {
  public:
    virtual void f0();
    virtual void Release();
};
class Target_299170 {
  public:
    char pad[8];
    Ref_299170* mRef;
    hulk_intptr Destroy(int flags);
};
extern void __cdecl thunk_FUN_00267090(Target_299170*);
hulk_intptr Target_299170::Destroy(int flags) {
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    if (flags & 1)
        thunk_FUN_00267090(this);
    return (hulk_intptr)this;
}