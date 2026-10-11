// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00328720 @ 0x00328720
namespace pure3d {
struct Base {
    virtual void slot0();
    char padding[0x7c];
    Base(unsigned int value);
};
struct d3dFBEffectsShader : Base {
    unsigned int field80;
    unsigned int field84;
    float field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned char field94;
    virtual void slot0();
    d3dFBEffectsShader(unsigned int value);
};
}
// Base constructor binds to FUN_00333520
pure3d::d3dFBEffectsShader::d3dFBEffectsShader(unsigned int value) : Base(value) {
    field80 = 0;
    field84 = 0;
    field8c = 0;
    field88 = 0.5f;
    field90 = 0xffffffff;
    field94 = 0;
}
