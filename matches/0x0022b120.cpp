#include "compat/ptr.h"
extern "C" double sqrt(double);
class Vec4 {
  public:
    float x, y, z, w;
    void Normalize();
};
void Vec4::Normalize() {
    hulk_freg scale = 1.0f / (hulk_freg)sqrt(x * x + y * y + z * z + w * w);  // the listing's order (MSVC 7.1 reassociates; clang does not)
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
}