// Same code shape as 0x00045800 (propagated; names are from that function)
#include "gen/global.h"

extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable_d6900 : public ::Overlay {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_d6900* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable_d6900*);
pure3d::NonCopyable_d6900* pure3d::NonCopyable_d6900::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}