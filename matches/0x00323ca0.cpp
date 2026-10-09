typedef unsigned char u8;
namespace pure3d {
extern int vt_d3d; extern int vt_ext;
class pddiExtension { public: virtual void a(); virtual void b(); virtual void c(); };
class pddiExtFrameBufferTexture { public: virtual void a(); virtual void b(); virtual void c(); };
struct Helper { void call(); };
void thunk_FUN_00267090(Helper*);
class d3dExtFrameBufferTexture : public pddiExtFrameBufferTexture, public pddiExtension { public: virtual d3dExtFrameBufferTexture* vfunc_0(u8); virtual void vfunc_1(); virtual void vfunc_2(); };
d3dExtFrameBufferTexture* d3dExtFrameBufferTexture::vfunc_0(u8 param) {
 *(int*)this = (int)&vt_d3d;
 ((Helper*)this)->call();
 *(int*)this = (int)&vt_ext;
 if (param & 1) thunk_FUN_00267090((Helper*)this);
 return this;
}
}