extern "C" double sqrt(double);
struct Vec {
    float x, y, z;
};
class Mat {
  public:
    float v[11];
    void Set(const Vec* p);
};
void Mat::Set(const Vec* p) {
    float x = p->x;
    float z = p->z;
    float inv = 1.0f / (float)sqrt(z * z + x * x);
    float b = inv * p->x;
    float a = inv * p->z;
    v[1] = 0;
    v[4] = 0;
    v[0] = a;
    v[5] = 1;
    v[6] = 0;
    v[9] = 0;
    v[2] = -b;
    v[8] = b;
    v[10] = a;
}