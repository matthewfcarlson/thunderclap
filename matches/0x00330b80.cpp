#include "gen/pure3d.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/platform/xbox/pure3d.h"
// data: skin_toon = DAT_00433818, toon = DAT_00433648


void* pure3d::d3dToonVertexShader::vfunc_23() {
    if ((*(char (*)[122])&this->f_04)[0x79])
        return (void*)(DAT_00433818);
    return (void*)(DAT_00433648);
}
