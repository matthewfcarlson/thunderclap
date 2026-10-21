#include "compat/ptr.h"
extern "C" float sqrt(float);
hulk_freg Sqrt(float x) {
    return sqrt(x);
}