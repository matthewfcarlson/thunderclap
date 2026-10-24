#include "gen/core.h"

extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable_45800 : public ::core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_45800* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable_45800*);
pure3d::NonCopyable_45800* pure3d::NonCopyable_45800::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}