#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
// data: ratio = DAT_003f3f10, scaleOut = DAT_00405578

extern "C" double tan(double);
extern "C" double atan(double);
void FUN_0009f790(float a, float b, float* c, float* d) {
    double t = tan(a * 0.008726646f) * DAT_003f3f10;
    *c = (float)(atan(b * t) * DAT_00405578);
    *d = (float)(atan(t) * DAT_00405578);
}