class Vec3 {
  public:
    float x, y, z;
    void Subtract(Vec3* other);
};
void Vec3::Subtract(Vec3* other) {
    x -= other->x;
    y -= other->y;
    z -= other->z;
}