struct Vec {
    int x, y, z;
};
class Obj {
    char pad[16];
    Vec v;

  public:
    bool Set(const Vec& a);
};
bool Obj::Set(const Vec& a) {
    v.x = a.x;
    v.y = a.y;
    v.z = a.z;
    return true;
}