#include "gen/pure3d.h"

extern const char zeroName[];
extern const char multiName[];
extern const char proximityName[];

void* pure3d::d3dLayeredLMapShader::vfunc_23() {
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_90))
        return (void*)(multiName);
    if (!(*(char *)&this->f_48) && (*(char *)&this->f_91))
        return (void*)(proximityName);
    return (void*)(zeroName);
}
