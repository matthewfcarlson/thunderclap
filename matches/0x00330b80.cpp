#include "gen/pure3d.h"

extern const char toon[];
extern const char skin_toon[];

void* pure3d::d3dToonVertexShader::vfunc_23() {
    if ((*(char (*)[122])&this->f_04)[0x79])
        return (void*)(skin_toon);
    return (void*)(toon);
}
