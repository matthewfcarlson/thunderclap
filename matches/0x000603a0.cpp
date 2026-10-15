struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0xb0];
    int m_b0, m_b4, m_b8;
    bool Set(const Vec3* v);
};
bool Obj::Set(const Vec3* v) {
    m_b0 = v->x;
    m_b4 = v->y;
    m_b8 = v->z;
    return true;
}
