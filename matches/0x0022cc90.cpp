#include "compat/ptr.h"
extern "C" double sqrt(double);
struct Vec {
    float x, y, z;
};
class Mat {
  public:
    float v[11];
    void Set(const Vec* p);
};
// x87: the reciprocal length stays in a register for b; MSVC spills it to a float slot (rounded) and computes a
// from the spilled copy
void Mat::Set(const Vec* p) {
    float x = p->x;
    float z = p->z;
    hulk_freg inv = 1.0f / (hulk_freg)sqrt((hulk_freg)z * z + (hulk_freg)x * x);
    hulk_freg b = inv * p->x;
    float spilled = inv;
    hulk_freg a = spilled * p->z;
    v[1] = 0;
    v[4] = 0;
    v[0] = a;
    v[5] = 1;
    v[6] = 0;
    v[9] = 0;
    v[2] = -b;
    v[8] = b;
    v[10] = a;
}
