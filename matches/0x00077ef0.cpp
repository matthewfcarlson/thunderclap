struct Vec3 {
    float x, y, z;
};
class Obj {
    char pad[0x14];
    float x, y, z;

  public:
    bool SetOffset_00077ef0(const Vec3* p);
};
bool Obj::SetOffset_00077ef0(const Vec3* p) {
    x = p->x;
    y = p->y;
    z = p->z;
    return true;
}