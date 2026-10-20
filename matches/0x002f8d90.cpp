#include "compat/ptr.h"
class Thing_2f8d90 {
  public:
    void Init(int* a, int* c, int* b, int* e, int d, int* f);
    int m[17];
};
void Thing_2f8d90::Init(int* a, int* c, int* b, int* e, int d, int* f) {
    m[0] = (hulk_intptr)a;
    m[1] = (hulk_intptr)b;
    m[2] = a[4];
    m[3] = b[4];
    m[4] = a[2];
    m[5] = b[2];
    m[11] = c[0];
    m[12] = c[1];
    m[13] = c[2];
    m[14] = e[0];
    m[15] = e[1];
    m[16] = e[2];
    m[9] = d;
    m[6] = f[0];
    m[7] = f[1];
    m[8] = f[2];
    m[10] = 0;
}