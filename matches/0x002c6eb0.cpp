struct Vec3_2c6eb0 {
    float x, y, z;
};
class Obj_2c6eb0 {
  public:
    char pad[0x10];
    Vec3_2c6eb0* points;
    void Interpolate(int index, Vec3_2c6eb0* value, float amount);
};
void Obj_2c6eb0::Interpolate(int index, Vec3_2c6eb0* value, float amount) {
    Vec3_2c6eb0* p = points + index;
    p->x = (value->x - p->x) * amount + p->x;
    p->y = (value->y - p->y) * amount + p->y;
    p->z = (value->z - p->z) * amount + p->z;
}