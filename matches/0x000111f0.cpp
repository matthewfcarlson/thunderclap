#include "compat/ptr.h"
struct V {
    float x, y, z;
    hulk_freg length2();
};
hulk_freg V::length2() {
    return x * x + y * y + z * z;
}