#include "compat/ptr.h"
float Helper(float, float, float);
hulk_freg Target(float param_1, float param_2) {
    return Helper(-3.1415927f, 3.1415927f, param_2 - param_1);
}