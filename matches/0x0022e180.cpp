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
void Plane_22e180::Set(Mat_22e180* m, P4* p) {
    m->Xform(p, this);
    float f = -p->w;
    V3_22e180 v;
    v.x = f * x;
    v.y = f * y;
    v.z = f * z;
    v.x += m->t.x;
    v.y += m->t.y;
    v.z += m->t.z;
    d = -((v.z) * z + v.y * y + v.x * x);
}
