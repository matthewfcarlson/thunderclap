extern "C" double sqrt(double);
class Vec4 {
  public:
    float x, y, z, w;
    void Normalize();
};
void Vec4::Normalize() {
    float scale = 1.0f / (float)sqrt(w * w + z * z + y * y + x * x);
    x *= scale;
    y *= scale;
    z *= scale;
    w *= scale;
}