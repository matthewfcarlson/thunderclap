#include "gen/pure3d.h"

typedef unsigned char u8;
namespace pure3d {

} // namespace pure3d
void* pure3d::d3dLightMapShader::vfunc_23() {
    if (!(*(u8 *)&this->f_48) && (*(u8 *)&this->f_88))
        return (void*)("layered_multicbv");
    if (!(*(u8 *)&this->f_48) && (*(u8 *)&this->f_89))
        return (void*)("layered_proximity");
    return (void*)("");
}
