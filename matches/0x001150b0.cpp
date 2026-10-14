struct Vec3 {
    int x;
    int y;
    int z;
};
class Obj {
  public:
    char pad[0x1c];
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