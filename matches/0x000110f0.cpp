class Vec3_110f0 {
  public:
    float x, y, z;
    void Subtract(Vec3_110f0* other);
};
void Vec3_110f0::Subtract(Vec3_110f0* other) {
    x -= other->x;
    y -= other->y;
    z -= other->z;
}