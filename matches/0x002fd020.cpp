#include "gen/owners.h"
void owners::Transform_2fd020::FUN_002fd020(float* v, float* out) {
    out[0] = m04 * v[0] + m08 * v[1] + m0c * v[2];
    out[1] = m10 * v[1] + m14 * v[2] + m08 * v[0];
    out[2] = m18 * v[2] + m0c * v[0] + m14 * v[1];
}