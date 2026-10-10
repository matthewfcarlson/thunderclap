// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::d3dExtFrameBufferTexture::vfunc_2 @ 0x00323c50
namespace D3D8 { struct D3DResource { unsigned flags; }; void __stdcall D3DResource_Release(D3DResource*); }
struct Texture { virtual void vfunc_0(); virtual void vfunc_1(); void FUN_00326300(int); };
namespace pure3d {
struct d3dExtFrameBufferTexture {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
 char pad[4];
 Texture* texture;
 D3D8::D3DResource* resource;
 unsigned flags;
};
void d3dExtFrameBufferTexture::vfunc_2() {
 if (texture) {
  texture->FUN_00326300(0);
  resource->flags ^= (flags ^ resource->flags) & 0x70000;
  texture->vfunc_1();
  D3D8::D3DResource_Release(resource);
  resource = 0;
  texture = 0;
 }
}
}