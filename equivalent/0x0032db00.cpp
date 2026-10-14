// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 4/4)
// FUN_0032db00 @ 0x0032db00
namespace D3D8 { void __fastcall D3DDevice_SetVertexShaderConstant1(unsigned int index, const float *values); }
struct ShaderState_32db00 {
 char pad[0x90];
 unsigned char enabled;
 char pad2[3];
 int mode;
 float value;
 void FUN_0032db00();
};
void ShaderState_32db00::FUN_0032db00() {
 float constants[4];
 float v = (mode == 1 || enabled == 0) ? 0.0f : value;
 constants[0] = v;
 constants[1] = v;
 constants[2] = v;
 constants[3] = v;
 D3D8::D3DDevice_SetVertexShaderConstant1(0x63, constants);
}