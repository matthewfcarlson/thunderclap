#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_0043397c[];
struct Ref_32b5e0 {
    virtual void f0();
    virtual void f1();
};
struct d3dShader_32b5e0 {
    void cleanup();
};
struct d3dLightMapShader_nv_32b5e0 {
    void cleanup();
};

void pure3d::d3dLightMapShader::FUN_0032b5e0() {
    *(void**)this = (void*)((hulk_intptr)DAT_0043397c);
    if ((*(Ref_32b5e0 * *)&this->f_80))
        (*(Ref_32b5e0 * *)&this->f_80)->f1();
    if ((*(Ref_32b5e0 * *)&this->f_84))
        (*(Ref_32b5e0 * *)&this->f_84)->f1();
    ((d3dLightMapShader_nv_32b5e0*)this)->cleanup();
}
