struct Vec3_689f0 {
    int x, y, z;
};
class Obj_689f0 {
  public:
    char pad[0x20];
    int a, b, c;
    bool Set(const Vec3_689f0* p);
};

bool Obj_689f0::Set(const Vec3_689f0* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return true;
}
