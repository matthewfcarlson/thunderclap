struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x28];
    int v28;
    int v2c;
    int v30;
    bool Set(const Vec3* p);
};
bool Obj::Set(const Vec3* p) {
    v28 = p->x;
    v2c = p->y;
    v30 = p->z;
    return true;
}
