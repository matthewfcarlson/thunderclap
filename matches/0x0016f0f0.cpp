struct Vec3_16f0f0 {
    int x, y, z;
};
class O_16f0f0 {
  public:
    char pad[0x18];
    int m18, m1c, m20;
    bool Fn(Vec3_16f0f0* v);
};
bool O_16f0f0::Fn(Vec3_16f0f0* v) {
    m18 = v->x;
    m1c = v->y;
    m20 = v->z;
    return true;
}
