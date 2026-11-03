#include "gen/owners.h"
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
void owners::Mat_22ba70::FUN_0022ba70(float x) {
    float s = (float)sin(x);
    a[1] = 0;
    a[4] = 0;
    a[5] = 1;
    a[6] = 0;
    a[9] = 0;
    float c = (float)cos(x);
    a[0] = c;
    a[2] = -s;
    a[8] = s;
    a[10] = c;
}