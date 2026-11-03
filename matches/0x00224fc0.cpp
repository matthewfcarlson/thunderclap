#include "compat/ptr.h"
float Helper(float, float, float);
hulk_freg Target(float from, float to) {
    return Helper(-3.1415927f, 3.1415927f, to - from);
}