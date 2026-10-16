#include "gen/pure3d.h"

namespace D3D8 {
void __stdcall D3DDevice_SetViewport(void*);
}
namespace pure3d {

} // namespace pure3d
void pure3d::d3dContext::vfunc_96(unsigned int x, unsigned int y) {
    this->f_17c = x;
    this->f_180 = y;
    D3D8::D3DDevice_SetViewport((char*)this + 0x16c);
}
