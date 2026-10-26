#include "gen/pure3d.h"
#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/pure3d.h"
// data: multiName = DAT_00433794, proximityName = DAT_00433778, zeroName = DAT_003f335c


void* pure3d::d3dLayeredLMapShader::vfunc_23() {
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_90))
        return (void*)(DAT_00433794);
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_91))
        return (void*)(DAT_00433778);
    return (void*)(((const char*)&DAT_003f335c));
}
