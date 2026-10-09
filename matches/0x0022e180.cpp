struct V3 {
    float x, y, z;
};
struct Mat {
    char pad[0x30];
    V3 t;
    void Xform(void* p, void* n);
};
struct P4 {
    float x, y, z, w;
};
struct Plane {
    float x, y, z, d;
    void Set(Mat* m, P4* p);
};
void Plane::Set(Mat* m, P4* p) {
    m->Xform(p, this);
    float f = -p->w;
    V3 v;
    v.x = f * x;
    v.y = f * y;
    v.z = f * z;
    v.x += m->t.x;
    v.y += m->t.y;
    v.z += m->t.z;
    d = -((v.z) * z + v.y * y + v.x * x);
}
