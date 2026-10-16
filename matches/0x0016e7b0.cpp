struct Vec3 {
    float x, y, z;
};
class Thing {
    char pad[0x2c];
    float x, y, z;

  public:
    bool Set(const Vec3* p);
};
bool Thing::Set(const Vec3* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return true;
}