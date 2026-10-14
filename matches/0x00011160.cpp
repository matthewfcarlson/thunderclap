class Vec3_11160 {
  public:
    float x, y, z;
    void AddScaled(float s, const Vec3_11160* v);
};
void Vec3_11160::AddScaled(float s, const Vec3_11160* v) {
    x = s * v->x + x;
    y = s * v->y + y;
    z = s * v->z + z;
}