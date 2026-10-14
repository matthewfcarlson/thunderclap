class Vec3_1655f0 {
  public:
    int x, y, z;
};

class Obj_1655f0 {
  public:
    char pad[0x18];
    int m18, m1c, m20;
    bool Set(const Vec3_1655f0* v);
};

bool Obj_1655f0::Set(const Vec3_1655f0* v) {
    m18 = v->x;
    m1c = v->y;
    m20 = v->z;
    return true;
}
