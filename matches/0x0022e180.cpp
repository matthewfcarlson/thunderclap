#include "compat/ptr.h"
struct V3_22e180 {
    float x, y, z;
};
struct Mat_22e180 {
    char pad[0x30];
    V3_22e180 t;
    void Xform(void* p, void* n);
};
struct P4 {
    float x, y, z, w;
};
struct Plane_22e180 {
    float x, y, z, d;
    void Set(Mat_22e180* m, P4* p);
};
#if defined(__clang__)
void Plane_22e180::Set(Mat_22e180* m, P4* p) {
    m->Xform(p, this);
    hulk_freg f = -p->w;
    // x stays in an x87 register; y and z products are stored (rounded), their sums are not
    float py = f * y;
    float pz = f * z;
    hulk_freg sx = f * x + m->t.x;
    hulk_freg sy = py + m->t.y;
    hulk_freg sz = pz + m->t.z;
    d = -(sz * z + sy * y + sx * x);
}
#else
void Plane_22e180::Set(Mat_22e180* m, P4* p) {
    m->Xform(p, this);
    hulk_freg f = -p->w;
    V3_22e180 v;
    v.x = f * x;
    v.y = f * y;
    v.z = f * z;
    v.x += m->t.x;
    v.y += m->t.y;
    v.z += m->t.z;
    d = -((v.z) * z + v.y * y + v.x * x);
}
#endif
