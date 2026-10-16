#include "gen/pure3d.h"

struct Vec3_292970 {
    float x, y, z;
};

char pure3d::Camera::vfunc_16(void* __p0, float r) { const Vec3_292970 * p = (const Vec3_292970 *)__p0;

    if (p->z + r < this->f_1c)
        return 0;
    if (p->z - r > this->f_20)
        return 0;
    if (this->f_2c * p->x + this->f_30 * p->z > r)
        return 0;
    if (this->f_34 * p->x + this->f_38 * p->z > r)
        return 0;
    if (this->f_40 * p->z + this->f_3c * p->y > r)
        return 0;
    if (this->f_48 * p->z + this->f_44 * p->y > r)
        return 0;
    return 1;
}
