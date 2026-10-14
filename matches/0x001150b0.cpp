struct Vec3_1150b0 {
    int x;
    int y;
    int z;
};
class Obj_1150b0 {
  public:
    char pad[0x1c];
    int a;
    int b;
    int c;
    bool Set(Vec3_1150b0* v);
};
bool Obj_1150b0::Set(Vec3_1150b0* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}