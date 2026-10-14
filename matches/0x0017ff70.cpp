// cl-flags: /O1
struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x30];
    Vec3 v;
    bool Set(Vec3* p);
};
bool Obj::Set(Vec3* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}
