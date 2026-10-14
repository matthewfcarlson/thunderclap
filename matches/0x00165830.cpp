struct Vec3 {
    int x, y, z;
};
class Obj {
  public:
    char pad[0x24];
    int a, b, c;
    bool Copy(Vec3* src);
};
bool Obj::Copy(Vec3* src) {
    a = src->x;
    b = src->y;
    c = src->z;
    return true;
}
