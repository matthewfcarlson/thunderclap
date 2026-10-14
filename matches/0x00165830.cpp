struct Vec3_165830 {
    int x, y, z;
};
class Obj_165830 {
  public:
    char pad[0x24];
    int a, b, c;
    bool Copy(Vec3_165830* src);
};
bool Obj_165830::Copy(Vec3_165830* src) {
    a = src->x;
    b = src->y;
    c = src->z;
    return true;
}
