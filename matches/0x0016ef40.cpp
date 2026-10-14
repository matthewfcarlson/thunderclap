struct Vec3_16ef40 {
    int x, y, z;
};
class Obj_16ef40 {
  public:
    char pad[0x28];
    int v28;
    int v2c;
    int v30;
    bool Set(const Vec3_16ef40* p);
};
bool Obj_16ef40::Set(const Vec3_16ef40* p) {
    v28 = p->x;
    v2c = p->y;
    v30 = p->z;
    return true;
}
