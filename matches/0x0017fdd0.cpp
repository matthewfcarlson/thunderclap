struct Vec3_17fdd0 {
    int a, b, c;
};
class X_17fdd0 {
  public:
    char pad[0x50];
    Vec3_17fdd0 v;
    bool Set(Vec3_17fdd0* src);
};
bool X_17fdd0::Set(Vec3_17fdd0* src) {
    v.a = src->a;
    v.b = src->b;
    v.c = src->c;
    return true;
}