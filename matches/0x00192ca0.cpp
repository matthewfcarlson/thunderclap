struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0xe0];
    int x, y, z;
    bool Set(const Vec3* v);
};
bool Obj::Set(const Vec3* v) {
    x = v->x;
    y = v->y;
    z = v->z;
    return true;
}
