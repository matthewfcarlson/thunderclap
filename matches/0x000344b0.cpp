class Vec3_344b0 {
  public:
    float x, y, z;
    Vec3_344b0* Scale(float s);
};
Vec3_344b0* Vec3_344b0::Scale(float s) {
    x *= s;
    y *= s;
    z *= s;
    return this;
}
