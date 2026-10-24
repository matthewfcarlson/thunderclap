#include "gen/pure3d.h"

#include "compat/ptr.h"
extern int vtable_32ba30;
struct d3dLightMapShader_nv_32ba30 {
    void Init(int);
};

pure3d::d3dLightMapShader* pure3d::d3dLightMapShader::FUN_0032ba30(int arg) {
    ((d3dLightMapShader_nv_32ba30*)this)->Init(arg);
    (*(int *)&this->f_80) = 0;
    (*(int *)&this->f_84) = 0;
    (*(char *)&this->f_88) = 0;
    (*(char *)&this->f_89) = 0;
    this->f_8c = 0;
    this->f_90 = 0;
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32ba30;
    return (d3dLightMapShader*)(this);
}
