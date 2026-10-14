struct Vec3_16f2a0 {
    int x, y, z;
};
class Obj_16f2a0 {
    char pad[0x20];
    int a, b, c;

  public:
    char Set(Vec3_16f2a0* p);
};
char Obj_16f2a0::Set(Vec3_16f2a0* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return 1;
}