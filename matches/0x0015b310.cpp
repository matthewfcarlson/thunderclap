struct V3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0xcc];
    int m0;
    int m1;
    int m2;
    bool Set(const V3* v);
};
bool Obj::Set(const V3* v) {
    m0 = v->x;
    m1 = v->y;
    m2 = v->z;
    return true;
}
