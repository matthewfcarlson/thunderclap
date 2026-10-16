// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 2/2)
// pure3d::pddiBaseContext::vfunc_44 @ 0x0031dbd0
// Sets the position of light `index` (0..7) in the context's light table and re-applies the light.
#include "gen/pure3d.h"

struct Vec3_31dbd0 {
    float x, y, z;
};
struct Light_31dbd0 {
    int unused0;
    Vec3_31dbd0 pos;
    float w;
    char rest[0x7c - 0x14];
};
namespace pure3d {

}
void pure3d::pddiBaseContext::vfunc_44(int index, int __p1) { const Vec3_31dbd0 * pos = (const Vec3_31dbd0 *)__p1;

    if (index < 8) {
        Vec3_31dbd0 p = *pos;
        Light_31dbd0 *l = &(*(Light_31dbd0 * *)&this->f_50)[index];
        l->pos = p;
        l->w = 1.0f;
        vfunc_110(index, 1);
    }
}
