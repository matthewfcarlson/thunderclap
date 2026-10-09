struct Vec3 {
    float x, y, z;
};
class Obj {
  public:
    char pad[0x10];
    Vec3* points;
    void Interpolate(int index, Vec3* value, float amount);
};
void Obj::Interpolate(int index, Vec3* value, float amount) {
    Vec3* p = points + index;
    p->x = (value->x - p->x) * amount + p->x;
    p->y = (value->y - p->y) * amount + p->y;
    p->z = (value->z - p->z) * amount + p->z;
}