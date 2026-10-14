class Vec3 {
  public:
    int x, y, z;
};

class Obj {
  public:
    char pad[0x18];
    int m18, m1c, m20;
    bool Set(const Vec3* v);
};

bool Obj::Set(const Vec3* v) {
    m18 = v->x;
    m1c = v->y;
    m20 = v->z;
    return true;
}
