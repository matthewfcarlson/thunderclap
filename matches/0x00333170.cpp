#include "compat/ptr.h"
extern "C" char DAT_00433f74[];
typedef unsigned char byte_333170;
struct Ref_333170 {
    virtual void f0();
    virtual void f1();
};
struct d3dBumpMapVertexShader_333170 {
    void* vf;
    char pad[0x7c];
    Ref_333170* m80;
    Ref_333170* m84;
    void FUN_00327930();
    d3dBumpMapVertexShader_333170* vfunc_3(byte_333170);
};
void thunk_FUN_00267090(d3dBumpMapVertexShader_333170*);
d3dBumpMapVertexShader_333170* d3dBumpMapVertexShader_333170::vfunc_3(byte_333170 param) {
    vf = (void*)((hulk_intptr)DAT_00433f74);
    if (m84)
        m84->f1();
    if (m80)
        m80->f1();
    FUN_00327930();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}