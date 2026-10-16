#include "gen/pure3d.h"

namespace D3D8 {
void __stdcall D3DDevice_SetRenderState_MultiSampleAntiAlias(unsigned int);
}

void pure3d::d3dExtAntialiasControl::vfunc_1(unsigned char value) {
    D3D8::D3DDevice_SetRenderState_MultiSampleAntiAlias(value);
}
