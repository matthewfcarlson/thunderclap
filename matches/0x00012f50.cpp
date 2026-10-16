struct Vec3 {
    int x, y, z;
};
class Obj {
    char pad[0xc0];
    Vec3 pos;

  public:
    Vec3* GetPos(Vec3* out);
};
Vec3* Obj::GetPos(Vec3* out) {
    *out = pos;
    return out;
}