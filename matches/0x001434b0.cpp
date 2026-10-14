struct Vec3 {
    float x, y, z;
};
class Obj {
  public:
    char pad[0x28];
    float a, b, c;
    char Set(Vec3* v);
};
char Obj::Set(Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}
