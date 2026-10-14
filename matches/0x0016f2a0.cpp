struct Vec3 {
    int x, y, z;
};
class Obj {
    char pad[0x20];
    int a, b, c;

  public:
    char Set(Vec3* p);
};
char Obj::Set(Vec3* p) {
    a = p->x;
    b = p->y;
    c = p->z;
    return 1;
}