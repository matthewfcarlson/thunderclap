struct Vec3_192270 {
    int x, y, z;
};
class Obj_192270 {
  public:
    char pad[0x40];
    int a;
    int b;
    int c;
    bool Set(Vec3_192270* v);
};
bool Obj_192270::Set(Vec3_192270* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}