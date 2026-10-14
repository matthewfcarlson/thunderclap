// cl-flags: /O1
struct Vec3_17ff70 {
    int x, y, z;
};
class Obj_17ff70 {
  public:
    char pad[0x30];
    Vec3_17ff70 v;
    bool Set(Vec3_17ff70* p);
};
bool Obj_17ff70::Set(Vec3_17ff70* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return true;
}
