struct Vec3 {
    int x, y, z;
};
class O {
  public:
    char pad[0x18];
    int m18, m1c, m20;
    bool Fn(Vec3* v);
};
bool O::Fn(Vec3* v) {
    m18 = v->x;
    m1c = v->y;
    m20 = v->z;
    return true;
}
