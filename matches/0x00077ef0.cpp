struct Vec3 {
    float x, y, z;
};
class Obj {
    char pad[0x14];
    float x, y, z;

  public:
    bool SetPos(const Vec3* p);
};
bool Obj::SetPos(const Vec3* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return true;
}