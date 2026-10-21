#include "compat/ptr.h"
extern "C" double __cdecl sin(double);
extern const float one;
extern const float pi;
extern const float halfpi;
extern const float half;
class Curve_ac6a0 {
  public:
    char p[16];
    float scale;
    char q[20];
    float cubic;
    float quad;
    float linear;
    float constant;
    hulk_freg Evaluate(float x);
};
hulk_freg Curve_ac6a0::Evaluate(float x) {
    hulk_freg t = ((one - x) * pi + halfpi);
    t = (hulk_freg)(sin((double)t) + one) * half - x;
    t = t * scale + x;
    hulk_freg a = t * t;
    hulk_freg b = a * t;
    hulk_freg c = b * cubic;
    hulk_freg d = a * quad;
    hulk_freg e = t * linear;
    return c + d + e + constant;  // the listing's order (MSVC 7.1 reassociates; clang does not)
}