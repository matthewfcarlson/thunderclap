#include "gen/pure3d.h"

typedef unsigned int uint;
struct Store_3272b0 {
    char pad[4];
    void* data;
};
void FUN_0031c230(int);
extern "C" void __cdecl memcpy(void*, const void*, unsigned int);

void pure3d::d3dPrimBuffer::vfunc_9(void* __p0, int count) { const void * src = (const void *)__p0;

    void* dst = (*(Store_3272b0 * *)&this->f_2c)->data;
    FUN_0031c230(0);
    memcpy(dst, src, count * 2);
    this->f_24 = count;
}
