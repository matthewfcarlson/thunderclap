struct Vec3_95e80 {
    float x, y, z;
    void Scale(float s, float const* v);
};
void Vec3_95e80::Scale(float s, float const* v) {
    x = s * v[0];
    y = s * v[1];
    z = s * v[2];
}