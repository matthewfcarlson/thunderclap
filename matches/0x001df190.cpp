#include "gen/global.h"

struct Vec3_1df190 {
    unsigned int x, y, z;
};
struct CSPManager_nv_1df190 {
    int Find(int arg);
    Vec3_1df190* Get(int index);
};

void* CSPManager::FUN_001df190(void* __p0, int arg) { Vec3_1df190 * out = (Vec3_1df190 *)__p0;

    int i = ((CSPManager_nv_1df190*)this)->Find(arg);
    if (i < 0) {
        out->x = 0x7f7fffff;
        out->y = 0x7f7fffff;
        out->z = 0x7f7fffff;
        return (void*)(out);
    }
    Vec3_1df190* p = ((CSPManager_nv_1df190*)this)->Get(i);
    *out = *p;
    return (void*)(out);
}
