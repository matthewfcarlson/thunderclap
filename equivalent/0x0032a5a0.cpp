// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 4/4)
// FUN_0032a5a0 @ 0x0032a5a0
#include "gen/owners.h"
namespace D3D8 { void __fastcall D3DDevice_SetVertexShaderConstant1(unsigned int index, const float *values); }
void owners::ShaderState_32a5a0::FUN_0032a5a0() {
 float v = (mode == 1 || enabled == 0) ? 0.0f : value;
 float data[4] = {v,v,v,v};
 D3D8::D3DDevice_SetVertexShaderConstant1(0x63,data);
}