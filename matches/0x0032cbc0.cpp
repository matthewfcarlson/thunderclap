#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_00433a8c[];
struct d3dProjectedTextureShader_nv_32cbc0 {
    void InitBase(void*);
    void InitMember();
};

pure3d::d3dProjectedTextureShader* pure3d::d3dProjectedTextureShader::FUN_0032cbc0(void* arg) {
    ((d3dProjectedTextureShader_nv_32cbc0*)this)->InitBase(arg);
    *(void**)this = (void*)((hulk_intptr)DAT_00433a8c);
    (*(int *)&this->f_80) = 0;
    (*(int *)&this->f_84) = 0;
    ((d3dProjectedTextureShader_nv_32cbc0*)(((pure3d::d3dProjectedTextureShader*)((char*)this + 0x88))))->InitMember();
    return (d3dProjectedTextureShader*)(this);
}
