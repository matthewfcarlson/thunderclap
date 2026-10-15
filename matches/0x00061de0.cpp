struct Vec3 {
    unsigned a, b, c;
};
class Obj {
  public:
    char pad[0xac];
    unsigned a, b, c;
    bool Set(const Vec3* o);
};
bool Obj::Set(const Vec3* o) {
    a = o->a;
    b = o->b;
    c = o->c;
    return 1;
}
