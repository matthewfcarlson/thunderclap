struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x40];
    int a;
    int b;
    int c;
    bool Set(Vec3* v);
};
bool Obj::Set(Vec3* v) {
    a = v->x;
    b = v->y;
    c = v->z;
    return true;
}