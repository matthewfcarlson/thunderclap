struct Vec3 {
    float x, y, z;
};
class Obj {
    char pad[0x24];
    float x, y, z;

  public:
    char Set(const Vec3* v);
};
char Obj::Set(const Vec3* v) {
    x = v->x;
    y = v->y;
    z = v->z;
    return 1;
}