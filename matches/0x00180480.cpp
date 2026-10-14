struct Vec3_180480 {
    int x, y, z;
};
class Obj_180480 {
  public:
    char pad[0x20];
    int a, b, c;
    bool Set(const Vec3_180480* v);
};
bool Obj_180480::Set(const Vec3_180480* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}
