// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0032b990 @ 0x0032b990
namespace D3D8 { void __fastcall D3DDevice_SetVertexShaderConstant1(int, const unsigned int*); }
struct ShaderState {
    char pad[0x88];
    unsigned char flag;
    char gap[3];
    int mode;
    unsigned int value;
    void FUN_0032b990();
};
void ShaderState::FUN_0032b990() {
    unsigned int v = value;
    if (mode == 1 || flag == 0) v = 0;
    unsigned int constants[4] = {v, v, v, v};
    D3D8::D3DDevice_SetVertexShaderConstant1(0x63, constants);
}