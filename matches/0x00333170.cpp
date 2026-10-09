typedef unsigned char byte;
struct Ref {
    virtual void f0();
    virtual void f1();
};
struct pure3d_d3dBumpMapVertexShader {
    void* vf;
    char pad[0x7c];
    Ref* m80;
    Ref* m84;
    void FUN_00327930();
    pure3d_d3dBumpMapVertexShader* vfunc_3(byte);
};
void thunk_FUN_00267090(pure3d_d3dBumpMapVertexShader*);
pure3d_d3dBumpMapVertexShader* pure3d_d3dBumpMapVertexShader::vfunc_3(byte param) {
    vf = (void*)0x433f74;
    if (m84)
        m84->f1();
    if (m80)
        m80->f1();
    FUN_00327930();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}