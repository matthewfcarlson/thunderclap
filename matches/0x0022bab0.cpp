#include "gen/owners.h"
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
void owners::Mat_22bab0::FUN_0022bab0(float angle) {
    float s = sin(angle);
    v[2] = 0.0f;
    v[6] = 0.0f;
    v[8] = 0.0f;
    v[9] = 0.0f;
    v[10] = 1.0f;
    float c = cos(angle);
    v[0] = c;
    v[1] = s;
    v[4] = -s;
    v[5] = c;
}