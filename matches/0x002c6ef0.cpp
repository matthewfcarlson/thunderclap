struct Vec3_2c6ef0 {
    float x, y, z;
};
class C_2c6ef0 {
  public:
    char pad[0x14];
    Vec3_2c6ef0* data;
    void f(int index, Vec3_2c6ef0* src, float t);
};
void C_2c6ef0::f(int index, Vec3_2c6ef0* src, float t) {
    Vec3_2c6ef0* p = data + index;
    p->x = (src->x - p->x) * t + p->x;
    p->y = (src->y - p->y) * t + p->y;
    p->z = (src->z - p->z) * t + p->z;
}