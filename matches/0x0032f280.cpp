// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::d3dRefractVertexShader::vfunc_13 @ 0x0032f280
namespace pure3d {
struct ShaderState {
    char pad[0xe4];
    int mode;
};
struct Texture {
    void FUN_00326300(int);
};
struct d3dRefractVertexShader {
    char pad0[0x14];
    ShaderState* state;
    char pad18[4];
    int value1c;
    char pad20[8];
    unsigned char value28;
    char pad29[0x84 - 0x29];
    Texture* texture;
    char pad88[0x94 - 0x88];
    int stored94;
    unsigned char stored98;
    void FUN_0032a260();
    void vfunc_13();
};
} // namespace pure3d
extern int DAT_0039db08;
extern int DAT_0039db60;
void pure3d::d3dRefractVertexShader::vfunc_13() {
    texture->FUN_00326300(0);
    if (1 != state->mode) {
        state->mode = 1;
        DAT_0039db08 |= 0x800;
        DAT_0039db60 = 1;
    }
    value1c = stored94;
    value28 = stored98;
    FUN_0032a260();
}