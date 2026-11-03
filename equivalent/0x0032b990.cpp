// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0032b990 @ 0x0032b990
#include "gen/owners.h"
namespace D3D8 { void __fastcall D3DDevice_SetVertexShaderConstant1(int, const unsigned int*); }
void owners::ShaderState_32b990::FUN_0032b990() {
    unsigned int v = value;
    if (mode == 1 || flag == 0) v = 0;
    unsigned int constants[4] = {v, v, v, v};
    D3D8::D3DDevice_SetVertexShaderConstant1(0x63, constants);
}