// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure2<HUDOverlay,void,int,math::Vector>::vfunc_2 @ 0x000cfd70
#include "gen/global.h"

struct Vector_cfd70 { float x, y, z; };
struct HUDOverlay_cfd70 {};

template <> void Closure2<HUDOverlay, void, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const void * args = (const void *)__p1;

    const int* words = (const int*)args;
    Vector_cfd70 vector;
    vector.x = *(const float*)(words + 1);
    vector.y = *(const float*)(words + 2);
    vector.z = *(const float*)(words + 3);
    ((*(HUDOverlay_cfd70 * *)&this->f_20)->*(*(void (HUDOverlay_cfd70::**)(int, Vector_cfd70))&this->f_1c))(words[0], vector);
}
