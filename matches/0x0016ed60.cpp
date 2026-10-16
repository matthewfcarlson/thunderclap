struct Vec {
    int x, y, z;
};
class Obj {
    char pad[0x38];
    int x, y, z;

  public:
    bool Set(Vec const& v);
};
bool Obj::Set(Vec const& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    return true;
}