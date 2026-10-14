struct Vec3_1434b0 {
    float x, y, z;
};
class Obj_1434b0 {
  public:
    char pad[0x28];
    float a, b, c;
    char Set(Vec3_1434b0* v);
};
char Obj_1434b0::Set(Vec3_1434b0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}
