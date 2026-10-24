#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_00433f74[];
struct I_332bb0 {
    virtual void f();
    virtual void Release();
};
struct d3dBumpMapVertexShader_nv_332bb0 {
    void common();
};

void pure3d::d3dBumpMapVertexShader::FUN_00332bb0() {
    *(volatile hulk_ulongptr*)this = ((hulk_intptr)DAT_00433f74);
    if ((*(I_332bb0 * *)&this->f_84))
        (*(I_332bb0 * *)&this->f_84)->Release();
    if ((*(I_332bb0 * *)&this->f_80))
        (*(I_332bb0 * *)&this->f_80)->Release();
    ((d3dBumpMapVertexShader_nv_332bb0*)this)->common();
}
