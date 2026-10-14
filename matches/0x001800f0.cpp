struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x68];
    Vec3 v;
    bool Set(const Vec3* p);
};
bool Obj::Set(const Vec3* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}