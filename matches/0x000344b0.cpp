class Vec3 {
  public:
    float x, y, z;
    Vec3* Scale(float s);
};
Vec3* Vec3::Scale(float s) {
    x *= s;
    y *= s;
    z *= s;
    return this;
}
