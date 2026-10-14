struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x20];
    int a, b, c;
    bool Set(const Vec3* v);
};
bool Obj::Set(const Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
