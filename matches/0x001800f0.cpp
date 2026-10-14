struct Vec3_1800f0 {
    int x, y, z;
};
class Obj_1800f0 {
  public:
    char pad[0x68];
    Vec3_1800f0 v;
    bool Set(const Vec3_1800f0* p);
};
bool Obj_1800f0::Set(const Vec3_1800f0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}