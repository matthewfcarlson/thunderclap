struct Vec3_146cb0 {
    int x;
    int y;
    int z;
};
class Obj_146cb0 {
  public:
    char pad[0x10];
    int a;
    int b;
    int c;
    char Set(Vec3_146cb0* v);
};
char Obj_146cb0::Set(Vec3_146cb0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return 1;
}
