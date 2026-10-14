struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x20];
    int a, b, c;
    bool Set(const Vec3* p);
};

bool Obj::Set(const Vec3* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return true;
}
