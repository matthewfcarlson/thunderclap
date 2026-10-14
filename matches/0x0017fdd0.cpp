struct Vec3 {
    int a, b, c;
};
class X {
  public:
    char pad[0x50];
    Vec3 v;
    bool Set(Vec3* src);
};
bool X::Set(Vec3* src) {
    v.a = src->a;
    v.b = src->b;
    v.c = src->c;
    return true;
}