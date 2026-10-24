#include "gen/pure3d.h"

#include "compat/ptr.h"
extern "C" char DAT_00433c24[];
struct d3dLayeredLMapShader_nv_32e800 {
    void Init(int);
};

pure3d::d3dLayeredLMapShader* pure3d::d3dLayeredLMapShader::FUN_0032e800(int arg) {
    ((d3dLayeredLMapShader_nv_32e800*)this)->Init(arg);
    *(void**)this = (void*)((hulk_intptr)DAT_00433c24);
    *(int*)((char*)this + 0x9c) = 0;
    return (d3dLayeredLMapShader*)(this);
}
