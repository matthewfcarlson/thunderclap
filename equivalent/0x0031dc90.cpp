// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_46 @ 0x0031dc90
#include "gen/pure3d.h"

namespace pure3d {

struct Vec3_31dc90 {
    float x, y, z;
};

struct Vec4_31dc90 {
    float x, y, z, w;
};

struct LightState_31dc90 {
    char pad00[0x24];
    Vec4_31dc90 direction;
    char pad34[0x7c - 0x34];
};

}
void pure3d::pddiBaseContext::vfunc_46(int index, int __p1) { const Vec3_31dc90 * direction = (const Vec3_31dc90 *)__p1;

    if (index < 8) {
        Vec4_31dc90 v;
        v.x = direction->x;
        v.y = direction->y;
        v.z = direction->z;
        v.w = 0.0f;
        (*(LightState_31dc90 * *)&this->f_50)[index].direction = v;
        vfunc_110(index, 1);
    }
}
