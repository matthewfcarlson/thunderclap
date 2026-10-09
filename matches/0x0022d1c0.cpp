extern "C" double sqrt(double);
extern const float one;
struct Vec3 {
    float x, y, z;
    void Normalize(const Vec3* p);
};
void Vec3::Normalize(const Vec3* p) {
    float s = p->z * p->z + p->y * p->y + p->x * p->x;
    float f = one / (float)sqrt((double)s);
    x = f * p->x;
    y = f * p->y;
    z = f * p->z;
}
