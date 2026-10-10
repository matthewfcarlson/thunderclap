// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 4/4)
// FUN_0032a5a0 @ 0x0032a5a0
namespace D3D8 { void __fastcall D3DDevice_SetVertexShaderConstant1(unsigned int index, const float *values); }
struct ShaderState {
 char pad[0x84];
 unsigned char enabled;
 char pad2[3];
 float value;
 char pad3[4];
 int mode;
 void FUN_0032a5a0();
};
void ShaderState::FUN_0032a5a0() {
 float v = (mode == 1 || enabled == 0) ? 0.0f : value;
 float data[4] = {v,v,v,v};
 D3D8::D3DDevice_SetVertexShaderConstant1(0x63,data);
}