struct Vec3 {
    int x;
    int y;
    int z;
};
class Obj {
  public:
    char pad[0x10];
    int a;
    int b;
    int c;
    char Set(Vec3* v);
};
char Obj::Set(Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}
