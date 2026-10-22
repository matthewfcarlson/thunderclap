#include "compat/ptr.h"
extern "C" double sqrt(double);
hulk_freg Sqrt(float x) {
    return sqrt(x);
}