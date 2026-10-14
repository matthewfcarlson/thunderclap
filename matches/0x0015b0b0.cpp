struct Vec3_15b0b0 {
    int x, y, z;
};
class Obj_15b0b0 {
  public:
    char pad[0x68];
    Vec3_15b0b0 v;
    char Set(const Vec3_15b0b0* p);
};
char Obj_15b0b0::Set(const Vec3_15b0b0* p) {
    v.x = p->x;
    v.y = p->y;
    v.z = p->z;
    return 1;
}
