#include "compat/ptr.h"
typedef unsigned char u8_323ca0;
namespace pure3d {
extern int vt_d3d;
extern int vt_ext;
class pddiExtension {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class pddiExtFrameBufferTexture {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
struct Helper_323ca0 {
    void call();
};
void thunk_FUN_00267090(Helper_323ca0*);
class d3dExtFrameBufferTexture : public pddiExtFrameBufferTexture, public pddiExtension {
  public:
    virtual d3dExtFrameBufferTexture* vfunc_0(u8_323ca0);
    virtual void vfunc_1();
    virtual void vfunc_2();
};
d3dExtFrameBufferTexture* d3dExtFrameBufferTexture::vfunc_0(u8_323ca0 param) {
    *(hulk_intptr*)this = (hulk_intptr)&vt_d3d;
    ((Helper_323ca0*)this)->call();
    *(hulk_intptr*)this = (hulk_intptr)&vt_ext;
    if (param & 1)
        thunk_FUN_00267090((Helper_323ca0*)this);
    return this;
}
} // namespace pure3d