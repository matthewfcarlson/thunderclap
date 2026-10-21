#include "compat/ptr.h"
extern "C" double sin(double);
extern "C" double cos(double);
struct X_22b1c0 {
    int a;
    float b;
    int c;
    float d;
    void Set(float);
};
void X_22b1c0::Set(float x) {
    a = 0;
    c = 0;
    hulk_freg h = x * 0.5f;
    b = (hulk_freg)sin(h);
    d = (hulk_freg)cos(h);
}