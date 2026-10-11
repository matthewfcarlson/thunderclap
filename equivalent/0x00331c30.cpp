// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00331c30 @ 0x00331c30
namespace pure3d {
struct Base {
    virtual void dummy();
    char padding[0x7c];
    Base(unsigned int);
};
struct d3dSpheremapVertexShader : Base {
    unsigned int field80, field84, color, field8c, field90, field94;
    virtual void dummy();
    d3dSpheremapVertexShader(unsigned int);
};
}
// Base constructor address: FUN_00333520
namespace pure3d {
d3dSpheremapVertexShader::d3dSpheremapVertexShader(unsigned int arg) : Base(arg) {
    field80 = 0;
    field84 = 0;
    color = 0x80808080;
    field8c = 0;
    field90 = 0;
    field94 = 0;
}
}