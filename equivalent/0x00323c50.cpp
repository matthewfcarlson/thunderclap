// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::d3dExtFrameBufferTexture::vfunc_2 @ 0x00323c50
#include "gen/pure3d.h"

namespace D3D8 { struct D3DResource { unsigned flags; }; void __stdcall D3DResource_Release(D3DResource*); }
struct Texture_323c50 { virtual void vfunc_0(); virtual void vfunc_1(); void FUN_00326300(int); };
namespace pure3d {

}
void pure3d::d3dExtFrameBufferTexture::vfunc_2() {
 if ((*(Texture_323c50 * *)&this->f_08)) {
  (*(Texture_323c50 * *)&this->f_08)->FUN_00326300(0);
  (*(D3D8::D3DResource * *)&this->f_0c)->flags ^= (this->f_10 ^ (*(D3D8::D3DResource * *)&this->f_0c)->flags) & 0x70000;
  (*(Texture_323c50 * *)&this->f_08)->vfunc_1();
  D3D8::D3DResource_Release((*(D3D8::D3DResource * *)&this->f_0c));
  (*(D3D8::D3DResource * *)&this->f_0c) = 0;
  (*(Texture_323c50 * *)&this->f_08) = 0;
 }
}
