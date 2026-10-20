#include "gen/pure3d.h"

void* pure3d::d3dLayeredShader::vfunc_23() {
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_90))
        return (void*)("layered_multicbv");
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_91))
        return (void*)("layered_proximity");
    return (void*)("");
}
