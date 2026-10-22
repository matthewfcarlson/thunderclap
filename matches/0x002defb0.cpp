#include "compat/ptr.h"
void* __cdecl alloc(hulk_uintptr);
class Shadow_2defb0 {
  public:
    Shadow_2defb0(int);
    virtual void v();
};
class ShadowSkin : public Shadow_2defb0 {
  public:
    ShadowSkin();
    virtual void v();
    void set(int, void*);
};
class ShadowSkinImpl_2defb0 {
  public:
    void* get();
};
ShadowSkin::ShadowSkin() : Shadow_2defb0(1) {
    ShadowSkinImpl_2defb0* b = (ShadowSkinImpl_2defb0*)alloc(0x80);
    set(0, b ? b->get() : 0);
}